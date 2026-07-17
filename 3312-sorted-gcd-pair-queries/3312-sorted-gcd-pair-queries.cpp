class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
     int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

       
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;   
    }
};