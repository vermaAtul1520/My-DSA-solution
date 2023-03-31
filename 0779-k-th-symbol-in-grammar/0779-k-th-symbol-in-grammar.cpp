class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) 
           return 0;
             
        int parent = kthGrammar(n-1, (k+1)/2);
        if (parent == 0) {
            return k % 2 == 0 ? 1 : 0;
        } else {
            return k % 2 == 0 ? 0 : 1;
        }
    }
};