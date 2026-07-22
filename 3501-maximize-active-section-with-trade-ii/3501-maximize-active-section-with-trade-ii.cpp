class SparseTable {
public:
    vector<vector<int>> st;
    int n;

    SparseTable() {}

    SparseTable(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;

        int k = 32 - __builtin_clz(n);
        st.push_back(nums);

        for (int i = 1; i < k; i++) {
            int len = n - (1 << i) + 1;
            vector<int> cur(len);
            int half = 1 << (i - 1);

            for (int j = 0; j < len; j++) {
                cur[j] = max(st[i - 1][j], st[i - 1][j + half]);
            }
            st.push_back(cur);
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};


class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
          int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<pair<int,int>> zeroGroups;      // {start,length}
        vector<int> zeroGroupIndex(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().second++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty()) {
            return vector<int>(queries.size(), ones);
        }

        vector<int> adjSums;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); i++) {
            adjSums.push_back(zeroGroups[i].second + zeroGroups[i + 1].second);
        }

        SparseTable st(adjSums);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left = -1;
            if (zeroGroupIndex[l] != -1) {
                auto g = zeroGroups[zeroGroupIndex[l]];
                left = g.second - (l - g.first);
            }

            int right = -1;
            if (zeroGroupIndex[r] != -1) {
                auto g = zeroGroups[zeroGroupIndex[r]];
                right = r - g.first + 1;
            }

            int endGroupFull =
                (s[r] == '1') ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1;

            int startGroupFull = zeroGroupIndex[l] + 1;

            int activeSections = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                activeSections = max(activeSections,
                                     ones + left + right);
            }
            else {

                int sIdx = startGroupFull;
                int eIdx = endGroupFull - 1;

                if (sIdx <= eIdx && !adjSums.empty()) {
                    activeSections = max(activeSections,
                                         ones + st.query(sIdx, eIdx));
                }
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <= endGroupFull) {

                activeSections = max(
                    activeSections,
                    ones + left +
                    zeroGroups[zeroGroupIndex[l] + 1].second);
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                activeSections = max(
                    activeSections,
                    ones + right +
                    zeroGroups[zeroGroupIndex[r] - 1].second);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};