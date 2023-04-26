class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0,dSum=0;
        for(auto &x:nums){
            sum+=x;
            while(x/10 || x%10){
                dSum+=(x%10);
                x/=10;
            }
        }
        return abs(sum-dSum);
    }
};