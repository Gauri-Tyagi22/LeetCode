class Solution {
public:

bool issafe(int row,int col,vector<string>board,int n){
    int r=row,c=col;
    while(r>=0){
        if(board[r][c]=='Q') return false;
        r--;
    }
    r=row;
    c=col;
    while(r>=0 && c>=0){
        if(board[r][c]=='Q') return false;
        r--;
        c--;
    }
    r=row,c=col;
    while(r>=0 && c<n){
        if(board[r][c]=='Q') return false;
        r--;
        c++;
    }
    return true;
}
int solve(int row,vector<string>board,int n){
    int count=0;
    if(row==n){
       
       return 1;
    }
    for(int col=0;col<n;col++){
        if(issafe(row,col,board,n)){
            board[row][col]='Q';
           count+= solve(row+1,board,n);
            board[row][col]='.';
        }
    }
    return count;
}
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        return solve(0,board,n);
       
    }
};