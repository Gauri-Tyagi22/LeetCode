class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0, distinct = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (freq[nums[right]]++ == 0)
                distinct++;

            while (distinct > k) {
                if (--freq[nums[left]] == 0)
                    distinct--;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int k = st.size();

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};