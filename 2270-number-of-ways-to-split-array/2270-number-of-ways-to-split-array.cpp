class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int count=0;
        long long presum=0;
        for(int i=0;i<nums.size()-1;i++){
          presum+=nums[i];
          if(presum>=(sum-presum)){
            count++;
          }

        }
        return count;
    }
};