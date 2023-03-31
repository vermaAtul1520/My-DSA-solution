class Solution {
public:
    int solve(int e,int n,vector<vector<int>> &dp){
        if(n==0 || n==1) return n;
        if(e==1) return n;
        
        if(dp[e][n]!=-1) return dp[e][n];
        
        int tmp=INT_MAX;
        for(int i=1;i<=n;i++){
            int nbreak=solve(e,n-i,dp);
            int bk=INT_MIN;
            if(e==2) bk=solve(1,i-1,dp);
            tmp=min(tmp,1+max(bk,nbreak));
        }
        return dp[e][n]=tmp;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return solve(2,n,dp); 
    }
};