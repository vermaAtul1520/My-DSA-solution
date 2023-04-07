class Solution {
public:
    // int dir[5]={0,-1,0,1,0};
   // void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis){
   //      int n=grid.size(),m=grid[0].size();
   //      // int t=1;
   //      queue<pair<int,int>>q;
   //      q.push({i,j});
   //      while(!q.empty()){
   //          auto p=q.front();
   //          q.pop();
   //          int r=p.first;
   //          int c=p.second;
   //          vis[r][c]=0;
   //          for(int i=0;i<4;i++){
   //              int row=r+dir[i];
   //              int col=c+dir[i+1];
   //              if(row<n && row>=0 && col<m && col>=0 && grid[row][col] && vis[row][col]){
   //                  // t++;
   //                  q.push({row,col});
   //              }
   //          }
   //      }
   //  }
    
    vector<int>dir={-1,0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis){
        vis[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+dir[k];
            int nj=j+dir[k+1];
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==1 && vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1));
        int ans=0;
        for(int i=0;i<n;i++){
            if(grid[i][0] && vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1] && vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j] && vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j] && vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};