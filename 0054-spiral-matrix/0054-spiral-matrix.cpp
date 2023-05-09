class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int up=0,down=matrix.size()-1;
        int lft=0,rht=matrix[0].size()-1;
        bool f=true;
        while(up<=down && lft<=rht){
            for(int i=lft;i<=rht;i++){
                ans.push_back(matrix[up][i]);
                f=false;
            }
            if(f) return ans;
            up++;
            f=true;
            for(int i=up;i<=down;i++){
                ans.push_back(matrix[i][rht]);
                f=false;
            }
            if(f) return ans;
            rht--;
            f=true;
            for(int i=rht;i>=lft;i--){
                ans.push_back(matrix[down][i]);
                f=false;
            }
            if(f) return ans;
            down--;
            f=true;
            for(int i=down;i>=up;i--){
                ans.push_back(matrix[i][lft]);
                f=false;
            }
            if(f) return ans;
            lft++;
        }
        return ans;
    }
};