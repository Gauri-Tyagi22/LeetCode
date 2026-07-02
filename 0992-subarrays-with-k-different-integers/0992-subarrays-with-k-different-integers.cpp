class Solution {
public:
int atmost(vector<int>&nums,int k){
    int left=0,d=0,ans=0;
    unordered_map<int,int>mp;
    for(int r=0;r<nums.size();r++){
        mp[nums[r]]++;
        if(mp[nums[r]]==1) d++;
        while(d>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                d--;
            }
            left++;
        }
        ans+=r-left+1;
        
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};