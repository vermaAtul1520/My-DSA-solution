class Solution {
public:
    long long solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        
        if(dp[n][m]!=-1) return dp[n][m];
        int lft=INT_MAX,rht=INT_MAX;
        lft=solve(n-1,m,grid,dp);
        rht=solve(n,m-1,grid,dp);
        
        return dp[n][m]=(long long )grid[n][m]+min(lft,rht);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};