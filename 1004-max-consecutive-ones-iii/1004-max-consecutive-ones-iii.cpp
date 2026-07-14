class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int ans=0;
        int zerocount=0;
        for(int r=0;r<nums.size();r++){
           if(nums[r]==0){
            zerocount++;
            while(zerocount>k){
                if(nums[left]==0) zerocount--;
                left++;
            }

           }
           ans=max(ans,r-left+1);
        }
        return ans;
    }
};