class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.size();
        int i=1;
        int sum=mp[s[0]];
        int prev=mp[s[0]];
        while(i<n){
            int t=mp[s[i]];
            if(prev<t){
                sum-=prev;
                sum+=(t-prev);
            }
            else{
                sum+=t;
            }
            prev=t;
            i++;
        }
        return sum;
    }
};