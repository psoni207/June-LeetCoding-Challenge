class Solution {
    private:
        int n, m;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n <= 2) return;
        
        m = board[0].size();
        if( m <= 2) return;
     
        helperSolve(board);
        
    }
    
    void helperSolve(vector<vector<char> > &board){
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == n-1 || j == m-1)){
                    callDFS(board,i,j);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void callDFS(vector<vector<char> > &board,int i, int j){
        
        board[i][j] = 'A';
        int x, y;
        for(int k = 0; k < 4; k++){
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O'){
                callDFS(board,x,y);
            }
        }
        
        
    }
};