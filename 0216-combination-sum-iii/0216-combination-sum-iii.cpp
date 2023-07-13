class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n, int k,vector<int> &ds, int ind){
        if(n==0 && k==0){
            ans.push_back(ds);
            return;
        }
        
        if(k<=0 || n<=0){
            return ;
        }
        
        for(int i=ind;i<=9;i++){
            if(i>n) break;
            ds.push_back(i);
            solve(n-i,k-1,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        if(k>n) return ans;
        solve(n,k,ds,1);
        return ans;
    }
};