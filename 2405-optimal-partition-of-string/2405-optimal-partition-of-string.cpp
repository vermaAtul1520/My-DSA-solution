class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n){
            unordered_map<char,int>mp;
            while(i<n && !mp[s[i]]){
                mp[s[i]]++;
                i++;
            }
            ans++;
        }
        return ans;
    }
};