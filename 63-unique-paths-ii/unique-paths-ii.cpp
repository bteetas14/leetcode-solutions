class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){

        int n = grid.size();
        int m = grid[0].size();

        if(row == 0 && col == 0) return 1;

        if(row<0 || row>n-1 || col<0 || col>m-1) return 0;

        if(grid[row][col]==1) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int up = solve(row-1, col, grid, dp);
        int left = solve(row, col-1, grid, dp);

        return dp[row][col] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[n-1][m-1]==1 || grid[0][0]==1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, grid, dp);
    }
};