class Solution {
public:
    
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) dp[1][i]=i;
        dp[1][1]=1;
        dp[2][1]=1;
        for(int t=2;t<=n;t++){
            int tmp=INT_MAX;
            for(int i=2;i<=t;i++){
                int nbreak=dp[2][t-i];
                int bk=dp[1][i-1];
                tmp=min(tmp,1+max(bk,nbreak));
            }
            dp[2][t]=tmp;
        }
        return dp[2][n];
    }
};