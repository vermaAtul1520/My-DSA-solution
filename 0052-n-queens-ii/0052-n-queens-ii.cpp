class Solution {
public:
    int ans=0;
    bool isSafe(int r,int c,vector<string> &ds,int n){
        int dr=r;
        int dc=c;
        while(dr>=0 && dc>=0){
            if(ds[dr][dc]=='Q') return false;
            dc--;
            dr--;
        }

        dc=c;
        dr=r;

        while(dc>=0){
            if(ds[dr][dc]=='Q')return false;
            dc--;
        }
        dc=c;
        dr=r;
        
        while(dc>=0 && dr<n){
            if(ds[dr][dc]=='Q') return false;
            dc--;
            dr++;
        }
        return true;
    }
    
    void solve(int col,vector<string> &ds,int n){
        if(col==n){
            ans++;
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,ds,n)){
                ds[row][col]='Q';
                solve(col+1,ds,n);
                ds[row][col]='.';
            }
        }
    }
    
    
    int totalNQueens(int n) {
        vector<string>ds(n);
         string s(n,'.');
         for(int i=0;i<n;i++){
             ds[i]=s;
         }

         solve(0,ds,n);
         return ans; 
    }
};
