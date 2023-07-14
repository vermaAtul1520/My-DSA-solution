class Solution {
public:
    vector<string>ans;
    unordered_map<char,vector<char>>mp={{'2',{'a','b','c'}},
                                      {'3',{'d','e','f'}},
                                      {'4',{'g','h','i'}},
                                      {'5',{'j','k','l'}},
                                      {'6',{'m','n','o'}},
                                      {'7',{'p','q','r','s'}},
                                      {'8',{'t','u','v'}},
                                      {'9',{'w','x','y','z'}}};
    void dfs(int ind,string &str,string digits){
        if(ind==digits.size()){
            ans.push_back(str);
            return;
        }
        
        vector<char>letters=mp[digits[ind]];
        for(auto x:letters){
            str.push_back(x);
            dfs(ind+1,str,digits);
            str.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        string str="";
        dfs(0,str,digits);
        return ans;
    }
};