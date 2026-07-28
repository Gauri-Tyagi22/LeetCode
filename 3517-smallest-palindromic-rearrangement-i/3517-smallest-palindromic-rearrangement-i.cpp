class Solution {
public:
    string smallestPalindrome(string s) {
         vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string first = "";
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            first.append(cnt[i] / 2, 'a' + i);

            if (cnt[i] % 2)
                mid = 'a' + i;
        }

        string ans = first;

        if (mid)
            ans += mid;

        reverse(first.begin(), first.end());
        ans += first;

        return ans;
    }
};