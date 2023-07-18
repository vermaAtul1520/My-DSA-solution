// class Solution {
// public:
//     long long mod=1000000007;
//     long long pow(int p, long long n){
//         if(n==0) return 1;
//         if(n==1) return p;
//         if(n%2==0){
//             return (pow(p,n/2)%mod*pow(p,n/2)%mod)%mod;
//         }
//         else{
//             return (p*(pow(p,n/2)%mod)*(pow(p,n/2)%mod))%mod;
//         }
//     }
    
//     int countGoodNumbers(long long n) {
//         long long ans=1;
        
//         if(n%2==0){
//             ans*= pow(20,n/2);
//         }
//         else{
//             long long a=pow(4,n/2)%mod;
//             long long b=pow(5,n-(n/2))%mod;
//             ans*= (a*b)%mod;
//         }
//         return int(ans%mod);
//     }
// };

class Solution {
private:
    long long powFunction(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = powFunction(x, n/2);
        ans *= ans;
        ans %= 1000000007;
        if(n%2==1){
            ans *= x;
            ans %= 1000000007;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (powFunction(5, even) * powFunction(4, odd))%1000000007;
    }
};