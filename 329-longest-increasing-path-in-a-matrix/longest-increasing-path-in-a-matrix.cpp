class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[r][c] != -1) return dp[r][c];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int maxi = 1;

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && nrow<matrix.size() && ncol>=0 && ncol<matrix[0].size() && matrix[nrow][ncol]>matrix[r][c]){
                maxi = max(maxi, 1+dfs(nrow, ncol, matrix, dp));
            }
        }
        return dp[r][c] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = -1e9;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi, dfs(i, j, matrix, dp));
            }
        }
        return maxi;
    }
};