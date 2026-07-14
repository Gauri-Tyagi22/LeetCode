class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

       
        sort(nums.begin(), nums.end());

        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int m = nums.size();
        int ans = n;
        int left = 0;

        
        for (int right = 0; right < m; right++) {

            while (nums[right] >= nums[left] + n) {
                left++;
            }

            int windowSize = right - left + 1;

            ans = min(ans, n - windowSize);
        }

        return ans;
    }
};