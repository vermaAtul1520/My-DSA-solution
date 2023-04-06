class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &v){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j] || v[i][j]){
            return 0;
        }
        v[i][j]=1;
        return 1+(solve(i,j+1,grid,v)+solve(i,j-1,grid,v)+solve(i+1,j,grid,v)+solve(i-1,j,grid,v));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !v[i][j]){
                    int tmp=0;
                    // v[i][j]=1;
                    tmp=solve(i,j,grid,v);
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;
    }
};