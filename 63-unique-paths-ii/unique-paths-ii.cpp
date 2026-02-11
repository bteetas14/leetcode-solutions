class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(row>n-1 || col>m-1 || obstacleGrid[row][col]==1) return 0;

        if(row==n-1 && col==m-1) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int down = solve(row+1, col, obstacleGrid, dp);
        int right = solve(row, col+1, obstacleGrid, dp);

        return dp[row][col] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};