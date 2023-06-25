class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>pref(n);
        vector<int>suf(n);
        int p=1,s=1;
        for(int i=0;i<n;i++){
            p*=nums[i];
            s*=nums[n-i-1];
            pref[i]=p;
            suf[n-i-1]=s;
        }
        ans[0]=suf[1];
        ans[n-1]=pref[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=pref[i-1]*suf[i+1];
        }
        return ans;
    }
};