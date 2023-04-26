class Solution {
public:
    int addDigits(int num) {
        int tmp=num;
        while(tmp/10){
            int t=0;
            while(num){
                t+=num%10;
                num/=10;
            }
            num=t;
            tmp=t;
        }
        return tmp;
    }
};