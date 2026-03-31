class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& minObs, int obs){
        int n = grid.size();
        int m = grid[0].size();

        if(r==n-1 && c==m-1) return obs;
        int mini = 1e9;

        if(minObs[r][c] <= obs) return 1e9;
        minObs[r][c] = obs;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newObs = obs;
                if(grid[nrow][ncol]==1){
                    newObs++;
                }
                mini = min(mini, dfs(nrow, ncol, grid, minObs, newObs));
            }
        }
        return mini;
    }
    int minimumObstacles(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> minObs(n, vector<int>(m, 1e9));

        // int obs = 0;
        // if(grid[0][0]==1) obs++;
        // if(grid[n-1][m-1]==1) obs++;
        // return dfs(0, 0, grid, minObs, obs);

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = -1;

        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        // obs r c

        while(!pq.empty()){
            auto [r, c] = pq.top().second;
            int obs = pq.top().first;
            pq.pop();

            if(r==n-1 && c==m-1) return obs;

            if(vis[r][c]==1) continue;
            vis[r][c] = 1;

            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newObs = obs;
                    if(grid[nrow][ncol]==1){
                        newObs++;
                    }
                    pq.push({newObs, {nrow, ncol}});
                }
            }
        }
        return ans;
    }
};