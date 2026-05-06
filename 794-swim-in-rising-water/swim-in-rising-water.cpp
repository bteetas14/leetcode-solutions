class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>, 
                    greater<tuple<int, int, int>>> pq;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto [time, r, c] = pq.top();
            pq.pop();

            if(r==n-1 && c==m-1) return time;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    pq.push({max(grid[nrow][ncol], time) , nrow, ncol});
                }
            }
        }
        return -1;
    }
};