class Solution {
public:
    string lastSubstring(string s) {
        int i=0,j=1,k=0;
        int n=s.size();
        while(j+k<n){
            if(s[i+k]==s[j+k]) k++;
            else if(s[i+k]<s[j+k]){
                i=max(i+k+1,j);
                // i=j;
                j=i+1;
                k=0;
            }
            else{
                j+=k+1;
                k=0;
            }
        }
        return s.substr(i);
    }
};
