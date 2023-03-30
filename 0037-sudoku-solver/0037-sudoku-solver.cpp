class Solution {
public:
    bool checkFill(char val,int x,int y,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][y]==val || board[x][i]==val || board[3*(x/3)+(i/3)][3*(y/3)+(i%3)]==val) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                if(board[x][y]=='.'){
                    for(char t='1';t<='9';t++){
                        if(checkFill(t,x,y,board)){
                            board[x][y]=t;
                            bool re=solve(board);
                            if(re){
                                return true;
                            }
                            board[x][y]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};