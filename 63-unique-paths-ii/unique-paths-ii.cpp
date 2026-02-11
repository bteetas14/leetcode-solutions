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

        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(0, 0, obstacleGrid, dp);

        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[n-1][m-1] = 1;

        for(int row=n-1;row>=0;row--){
            for(int col=m-1;col>=0;col--){

                if(row==n-1 && col==m-1) continue;
                if(obstacleGrid[row][col]==1) continue;

                long long down = 0, right = 0;

                if(row<n-1) down = dp[row+1][col];
                if(col<m-1) right = dp[row][col+1];
                             
                dp[row][col] = (down+right);
            }
        }
        return dp[0][0];
    }
};