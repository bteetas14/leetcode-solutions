class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis){

        int n = heights.size();
        int m = heights[0].size();

        vis[r][c] = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol]>=heights[r][c]){
                dfs(nrow, ncol, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int r=0;r<n;r++){
            dfs(r, 0, heights, pacific);
            dfs(r, m-1, heights, atlantic);
        }

        for(int c=0;c<m;c++){
            dfs(0, c, heights, pacific);
            dfs(n-1, c, heights, atlantic);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};