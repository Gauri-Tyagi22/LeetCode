class Solution {
public:
vector<vector<int>>ans;
void solve(vector<int>&candidates,int i,int target,vector<int>curr){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(i==candidates.size() || target<0) return;
    curr.push_back(candidates[i]);
    solve(candidates,i+1,target-candidates[i],curr);

    curr.pop_back();
      while(i + 1 < candidates.size() &&
              candidates[i] == candidates[i + 1])
            i++;
    solve(candidates,i+1,target,curr);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
          sort(candidates.begin(), candidates.end());
        solve(candidates,0,target,curr);
        return ans;
    }
};