class Solution {
public:
    vector<int>dic{0,1,0,-1,0};
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        
        grid[i][j]='0';
        for(int t=0;t<4;t++){
            int r=i+dic[t];
            int c=j+dic[t+1];
            dfs(r,c,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};