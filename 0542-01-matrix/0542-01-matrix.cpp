class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){
                     q.push({nx,ny});
                     dist[nx][ny]=1+dist[r][c];
                }
            }
        }
        return dist;
    }
};