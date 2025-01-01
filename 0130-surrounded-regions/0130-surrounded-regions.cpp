class Solution {
int dirs[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
bool safe(int nri,int ncj, int n , int m) {

    return nri >= 0 && nri < n && ncj >= 0 && ncj < m ;
}
private: 
  void dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,int ri,int cj, int n, int m){
       vis[ri][cj] = true;

       for(int i = 0 ; i < 4; i++) {
         int nri = ri + dirs[i][0];
         int ncj = cj + dirs[i][1];
         if(safe(nri,ncj,n,m) and !vis[nri][ncj] and board[nri][ncj] == 'O') {
            dfs(board,vis,nri,ncj,n,m);
         }
       }

  }
        

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int j = 0; j < m; j++){
            if(!vis[0][j] and board[0][j] == 'O'){
                dfs(board,vis,0,j,n,m);

            }
            if(!vis[n-1][j] and board[n-1][j] == 'O') {
                dfs(board,vis,n-1,j,n,m);
            }
            
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] and board[i][0] == 'O') {
                dfs(board,vis,i,0,n,m);
            }
            if(!vis[i][m-1] and board[i][m-1] == 'O') {
                dfs(board,vis,i,m-1,n,m);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(board[i][j] == 'O' and !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};