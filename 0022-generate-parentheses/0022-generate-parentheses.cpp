class Solution {
public:
    vector<string>ans;
    void solve(int op,int cl,string &str){
        if(cl<op || op<0) return;
        if(cl==0 && op==0){
            ans.push_back(str);
            return;
        }
        str.push_back('(');
        solve(op-1,cl,str);
        str.pop_back();
        str.push_back(')');
        solve(op,cl-1,str);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        solve(n,n,str);
        return ans;
    }
};