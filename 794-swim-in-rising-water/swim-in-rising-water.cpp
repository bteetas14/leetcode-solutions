class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row==n-1 && col==m-1) return time;
            if(vis[row][col]==1) continue;
            vis[row][col] = 1;

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    int t = max(grid[nrow][ncol], time);
                    pq.push({t, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};