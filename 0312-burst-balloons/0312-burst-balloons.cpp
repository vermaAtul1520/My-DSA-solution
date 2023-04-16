class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        long long int mx=INT_MIN;
        for(int t=i;t<=j;t++){
            long long int c=(nums[t]*nums[i-1]*nums[j+1])+solve(i,t-1,nums,dp)+solve(t+1,j,nums,dp);
            mx=max(mx,c);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return solve(1,n,nums,dp);
    }
};