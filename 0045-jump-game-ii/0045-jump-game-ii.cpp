class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,curr=0;long long farthest=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,(long long) (i+nums[i]));
            if(i==curr){
                jump++;
                curr=farthest;
            }
        }
        return jump;
    }
};