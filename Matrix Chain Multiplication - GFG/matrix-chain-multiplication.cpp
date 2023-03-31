//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(int i,int j,int arr[],vector<vector<int>> &dp){
    //     if(i==j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=INT_MAX;
    //     for(int k=i;k<j;k++){
    //         int step=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
    //         ans=min(ans,step);
    //     }
    //     return dp[i][j]=ans;
    // }
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>0;i--){
            for(int j=i+1;j<N;j++){
                int ans=INT_MAX;
                for(int k=i;k<j;k++){
                    int step=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                    ans=min(ans,step);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends