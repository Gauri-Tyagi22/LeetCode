class Solution {
public:
vector<vector<int>>ans;
void solve(vector<int>candidates,int i,int target,vector<int>curr){
    
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(i==candidates.size()) return;
    if(candidates[i]<=target){
    curr.push_back(candidates[i]);
    solve(candidates,i,target-candidates[i],curr);
    curr.pop_back();
    }
    solve(candidates,i+1,target,curr);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(candidates,0,target,curr);
        return ans;
    }
};