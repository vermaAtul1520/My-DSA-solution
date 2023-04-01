class Solution {
public:
	vector<vector<vector<int>>> dp;
    int mod=1e9+7;
	int rec(int x, int y, int currRem, vector<vector<int>>& grid, int& k){
		if (x >= grid.size() || y >= grid[0].size()) return 0;
		if (x == grid.size() - 1 && y == grid[0].size() - 1){
			if ((grid[x][y] + currRem) % k == 0)
				return 1;
			return 0;
		}
        
		if (dp[x][y][currRem] != -1) return dp[x][y][currRem];
		int nextRem = (grid[x][y] + currRem) % k;
        
		return dp[x][y][currRem] = (rec(x + 1, y, nextRem, grid, k) + rec(x, y + 1, nextRem, grid, k)) % mod;
	}

	int numberOfPaths(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> temp(n, vector<int>(k, -1));
		dp.resize(m, temp);
		return rec(0, 0, 0, grid, k);
	}
};