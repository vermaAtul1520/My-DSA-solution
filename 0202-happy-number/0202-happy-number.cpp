class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(n > 1 && n <= 4)
            return false;
        int tmp = 0;
        while(n > 0){    
            int m = n % 10;    
            tmp = tmp + (m * m);    
            n = n / 10;
        }
        return isHappy(tmp);
    }
};