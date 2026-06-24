class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int pos=nums.size()-(lower_bound(nums.begin(),nums.end(),1)-nums.begin());
        return max(pos,neg);
        
    }
};