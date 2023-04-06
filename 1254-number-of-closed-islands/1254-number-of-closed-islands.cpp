class Solution {
public:
    vector<int>dir={0,-1,0,1,0};
    void bfs(int i,int j,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=1;
        while(q.size()){
            auto p=q.front();
            q.pop();
            int r=p.first,c=p.second;
            for(int i=0;i<4;i++){
                int row=r+dir[i];
                int col=c+dir[i+1];
                
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==0){
                    q.push({row,col});
                    grid[row][col]=1;
                }
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int  ans=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                bfs(i,0,grid);
            }
            if(grid[i][m-1]==0){
                bfs(i,m-1,grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                bfs(0,j,grid);
            }
            if(grid[n-1][j]==0){
                bfs(n-1,j,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        
        return ans;
    }
};