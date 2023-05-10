class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int t=0;
        int up=0,down=n-1,lft=0,rht=n-1;
        int dir=0;
        while(t<n*n && up<=down && lft<=rht){
            if(dir==0){
                for(int i=lft;i<=rht;i++){
                    ans[up][i]=++t;
                    // t++;
                }
                up++;
            }
            else if(dir==1){
                for(int i=up;i<=down;i++){
                    ans[i][rht]=++t;
                    // t++;
                }
                rht--;
            }
            else if(dir==2){
                for(int i=rht;i>=lft;i--){
                    ans[down][i]=++t;
                    // t++;
                }
                down--;
            }
            else if(dir==3) {
                for(int i=down;i>=up;i--){
                    ans[i][lft]=++t;
                    // t++;
                }
                lft++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};