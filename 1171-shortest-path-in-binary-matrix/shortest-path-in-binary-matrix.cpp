class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        // dist, {row, col}

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        q.push({1, {0,0}});
        dist[0][0] = 0;

        int delrow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            int d = q.front().first;
            auto [row, col] = q.front().second;

            if(row==n-1 && col==m-1) return d;
            q.pop();

            for(int i=0;i<8;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist[nrow][ncol]>d+1){
                    dist[nrow][ncol] = d+1;
                    q.push({d+1, {nrow, ncol}});
                }
            }
        }
        if(dist[n-1][m-1] != 1e9) return dist[n-1][m-1];
        return -1;
    }
};