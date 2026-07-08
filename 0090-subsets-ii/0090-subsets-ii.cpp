class Solution {
public:
vector<vector<int>>ans;
void solve(vector<int>&nums,int i,vector<int> curr){
    if(i==nums.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    solve(nums,i+1,curr);
    curr.pop_back();
    while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
    solve(nums,i+1,curr);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        solve(nums,0,curr);
        return ans;
        
    }
};