class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis){
    int n=board.size();
    int m=board[0].size();
    vis[i][j]=1;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int nx=dx[k]+i;
        int ny=dy[k]+j;
        if( nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && board[nx][ny]=='O'){
            dfs(nx,ny,board,vis);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O')
               dfs(i,0,board,vis);
        }
          for(int i=0;i<n;i++){
            if(!vis[i][m-1] && board[i][m-1]=='O')
               dfs(i,m-1,board,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                  board[i][j]='X';
            }
        }

    }
};