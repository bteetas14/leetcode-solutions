class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 1});

        while(!q.empty()){
            auto [r, c] = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(vis[r][c]==1) continue;
            vis[r][c] = 1;

            if(r==n-1 && c==m-1) return dist;

            for(int i=0;i<8;i++){
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                    q.push({{nrow, ncol}, dist+1});
                }
            }
        }
        return -1;
    }
};