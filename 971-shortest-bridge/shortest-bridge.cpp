class Solution {
public:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    void dfs(int r, int c, int n, vector<vector<int>>& vis, vector<vector<int>>& grid, queue<pair<pair<int, int>, int>>& q){
        vis[r][c] = 1;
        q.push({{r, c}, 0});

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                dfs(nrow, ncol, n, vis, grid, q);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int minSteps = 1e9;
        bool found = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i, j, n, vis, grid, q);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz>0){
                auto [r, c] = q.front().first;
                int steps = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0){
                        if(grid[nrow][ncol]==0){
                            vis[nrow][ncol] = 1;
                            q.push({{nrow, ncol}, steps+1});
                        }
                        else if(grid[nrow][ncol]==1){
                            minSteps = min(minSteps, steps);
                        }
                    }
                }
                sz--;
            }
        }
        return minSteps;
    }
};