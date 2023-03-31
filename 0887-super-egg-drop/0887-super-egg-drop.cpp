class Solution {
public:
//     int solve(int k,int n,vector<vector<int>> &dp){
//         if(n==0 || n==1) return n;
//         if(k==1) return n;
        
//         if(dp[k][n]!=-1) return dp[k][n];
//         int ans=INT_MAX;
        
//         for(int t=1;t<=n;t++){
//            ans=min(ans,1+max(solve(k-1,t-1,dp),solve(k,n-t,dp)));
//         }
//         return dp[k][n]=ans;
//     }
    
//     int superEggDrop(int k, int n) {
//         vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
//         return solve(k,n,dp);
//     }
    
    
    int solve(int k,int n,vector<vector<int>> &dp){
        if(n==0 || n==1) return n;
        if(k==1) return n;
        
        if(dp[k][n]!=-1) return dp[k][n];
        int ans=INT_MAX;
        
        for(int t=1;t<=n;t++){
           ans=min(ans,1+max(solve(k-1,t-1,dp),solve(k,n-t,dp)));
        }
        return dp[k][n]=ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) dp[1][i]=i;
        for(int i=0;i<=k;i++){
           dp[i][1]=1;
        }
        
        for(int i=2;i<=k;i++){
           for(int j=2;j<=n;j++){
               int left = 1, right = j;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (dp[i-1][mid-1] < dp[i][j-mid]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                dp[i][j] = 1 + dp[i-1][left-1];
            }
        }
        return dp[k][n];
    }
};