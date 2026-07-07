class Solution {
public:
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        int count=0;
        int n=nums.size();
        vector<long long> pow2(n);
        pow2[0] = 1;
const int MOD = 1e9 + 7;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        while(left<=right){
            long long sum=nums[left]+nums[right];
            if(sum<=target){
       count = (count + pow2[right - left]) % MOD;
          left++;
          
            } 
           
            else right--;
        }
        return count;
    }
};