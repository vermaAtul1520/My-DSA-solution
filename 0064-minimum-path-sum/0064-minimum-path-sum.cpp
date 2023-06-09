class Solution {
public:
//     long long solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
//         // if(n==0 && m==0) return grid[0][0];
//         if(n<0 || m<0) return INT_MAX;
        
//         if(dp[n][m]!=-1) return dp[n][m];
//         int lft=INT_MAX,rht=INT_MAX;
//         lft=solve(n-1,m,grid,dp);
//         rht=solve(n,m-1,grid,dp);
//         if(lft==INT_MAX && rht==INT_MAX)
//             lft=0,rht=0;
//         return dp[n][m]=(long long )grid[n][m]+min(lft,rht);
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e7));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int lft=1e7,rht=1e7;
                lft=dp[i-1][j];
                rht=dp[i][j-1];
                if(lft==1e7 && rht==1e7)
                    lft=0,rht=0;
                dp[i][j]=grid[i-1][j-1]+min(lft,rht);
            }
        }
        return dp[n][m];
    }
};