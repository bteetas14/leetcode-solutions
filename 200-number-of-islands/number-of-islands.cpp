class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};