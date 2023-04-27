class Solution {
public:
    vector<int>dir{0,-1,0,1,0};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int t){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;
        
        if(image[sr][sc]!=t) return;
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int r=sr+dir[i];
            int c=sc+dir[i+1];
            dfs(image,r,c,color,t);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};