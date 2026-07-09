class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>group(n);
        group[0]=0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                group[i]=group[i-1];
            }
            else group[i]=group[i-1]+1;
        }
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            if(group[u]==group[v]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};