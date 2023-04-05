class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
       //  int mn[n],mx[n];
       //  mn[0]=nums[0];
       //  mx[n-1]=nums[n-1];
       // for(int i=1;i<n;i++){
       //     if(nums[i]==0){
       //        mn[i]=mn[i-1];
       //     }
       //     else{
       //        mn[i]=min(nums[i],mn[i-1]);
       //     }
       // }
       //  for(int i=n-2;i>=0;i--){
       //      mx[i]=max(mx[i+1],nums[i]);
       //  }
       //  for(auto x:mn){
       //      cout<<x<<" ";
       //  }
       //  cout<<endl;
       //  for(auto x:mx){
       //      cout<<x<<" ";
       //  }
       //  cout<<endl;
       //  int ans=0;
       //  for(int i=0;i<n;i++){
       //      ans=max((mx[i]+mn[i]+1)/2,ans);
       //  }
        long long ans=nums[0],prevSum=nums[0];
        for(int i=1;i<n;i++){
            prevSum+=nums[i];
            ans=max(ans,(prevSum+i)/(i+1));
        }
        return ans;
    }
};