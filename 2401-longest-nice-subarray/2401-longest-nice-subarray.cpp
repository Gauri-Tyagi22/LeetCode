class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
      int left=0;
      int mask=0;
      int ans=0;
      for(int r=0;r<nums.size();r++){
        while(nums[r]&mask){
            mask^=nums[left];
            left++;
        }
        mask|=nums[r];
        ans=max(ans,r-left+1);
      }  
      return ans;
    }
};