class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis,int &node,int &edges){
    vis[i]=true;
    node++;
    edges+=adj[i].size();
    for(int nei:adj[i]){
        if(!vis[nei]){
            dfs(nei,adj,vis,node,edges);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
       int ans=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
             int node=0;
        int edges=0;
        dfs(i,adj,vis,node,edges);
        int acc=edges/2;
        int exp=node*(node-1)/2;
        if(acc==exp) ans++;
        }
       }
return ans;
    }
};