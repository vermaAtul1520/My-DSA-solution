class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
             return;
        }
        
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i<0){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+(i+1),nums.end());
        int ub=upper_bound(nums.begin()+(i+1),nums.end(),nums[i])-nums.begin();
        swap(nums[i],nums[ub]);
    }
};