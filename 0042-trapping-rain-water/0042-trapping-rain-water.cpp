class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prevMax(n,-1);
        vector<int>sufMax(n,-1);
        int curMax=height[0];
        
        for(int i=1;i<n;i++){
            if(curMax<height[i]){
                prevMax[i]=-1;
                curMax=height[i];
            }
            else{
                prevMax[i]=curMax;
            }
        }
        curMax=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(curMax<height[i]){
                sufMax[i]=-1;
                curMax=height[i];
            }
            else{
                sufMax[i]=curMax;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int t=(min(prevMax[i],sufMax[i]))-height[i];
            ans+=(t>=0? t: 0);
        }
        return ans;
    }
};