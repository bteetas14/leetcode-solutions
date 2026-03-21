class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        int n = heights.size();
        int m = heights[0].size();
        vis[row][col] = true;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol]>=heights[row][col]){
                dfs(nrow, ncol, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ds;

        for(int col=0;col<m;col++){
            dfs(0, col, heights, pacific);
            dfs(n-1, col, heights, atlantic);
        }
        for(int row=0;row<n;row++){
            dfs(row, 0, heights, pacific);
            dfs(row, m-1, heights, atlantic);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ds.push_back({i, j});
                }
            }
        }
        return ds;
    }
};