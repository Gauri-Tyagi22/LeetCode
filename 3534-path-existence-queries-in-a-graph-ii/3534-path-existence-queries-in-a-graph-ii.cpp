class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
  vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        vector<int> s(n), posOf(n);
        for (int i = 0; i < n; i++) {
            s[i] = nums[idx[i]];
            posOf[idx[i]] = i;
        }

       
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++)
            comp[i] = comp[i-1] + ((s[i] - s[i-1] <= maxDiff) ? 0 : 1);

       
        vector<int> R(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n && s[r+1] - s[i] <= maxDiff) r++;
            R[i] = r;
        }

        
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++; 

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = R;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];

        int Q = queries.size();
        vector<int> ans(Q);
        for (int i = 0; i < Q; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) { ans[i] = 0; continue; }

            int pu = posOf[u], pv = posOf[v];
            if (comp[pu] != comp[pv]) { ans[i] = -1; continue; }

            if (pu > pv) swap(pu, pv);

            int cur = pu, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            steps += 1; 
            ans[i] = steps;
        }

        return ans;
    }
};