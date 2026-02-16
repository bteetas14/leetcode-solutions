class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap: {time, row, col}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Push starting cell
        pq.push({grid[0][0], {0, 0}});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if (vis[row][col]) continue;
            vis[row][col] = 1;

            // If reached destination
            if (row == n-1 && col == n-1)
                return time;

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol]) {

                    int newTime = max(time, grid[nrow][ncol]);
                    pq.push({newTime, {nrow, ncol}});
                }
            }
        }

        return -1; // Should never reach here
    }
};
