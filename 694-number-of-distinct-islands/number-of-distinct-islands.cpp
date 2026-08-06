class Solution {
public:
    void dfs(int r, int c, vector<pair<int, int>>& island, vector<vector<int>>& grid, vector<vector<int>>& vis){

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        island.push_back({r, c});

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==0 && grid[nr][nc]==1){
                dfs(nr, nc, island, grid, vis);
            }
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {

        set<vector<pair<int, int>>> st;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int, int>> island;
                    dfs(i, j, island, grid, vis);

                    int mx = island[0].first;
                    int my = island[0].second;

                    for(auto &it:island){
                        it.first = it.first-mx;
                        it.second = it.second-my;
                    }
                    sort(island.begin(), island.end());
                    st.insert(island);
                }
            }
        }
        return st.size();
    }
};