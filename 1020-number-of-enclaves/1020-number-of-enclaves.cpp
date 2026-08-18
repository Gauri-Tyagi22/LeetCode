class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){
    vis[r][c]=1;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nx=r+dx[i];
        int ny=c+dy[i];
       if(nx<n && nx>=0 && ny<m && ny>=0 && !vis[nx][ny] && grid[nx][ny]==1)
            dfs(nx,ny,grid,vis);
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1) dfs(0,j,grid,vis);
        }
        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && grid[n-1][j]==1) dfs(n-1,j,grid,vis);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1) dfs(i,0,grid,vis);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1]==1) dfs(i,m-1,grid,vis);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};