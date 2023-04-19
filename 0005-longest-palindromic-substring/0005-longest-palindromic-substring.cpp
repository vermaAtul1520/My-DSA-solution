class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int t=0;
        int start,end;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        
        for(int l=3;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
           for(int j=i;j<n;j++){
               if(dp[i][j]==1){
                    dp[i][j]=1;
                    if(t<(j-i+1)){
                       start=i;
                       t=j-i+1;
                    }
                }
           }
        }
        return s.substr(start,t);
    }
};