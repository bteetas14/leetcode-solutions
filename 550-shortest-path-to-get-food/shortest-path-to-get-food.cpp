class Solution {
public:
    int getFood(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='*'){
                    pq.push({0, {i, j}});
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        while(!pq.empty()){
            auto [r, c] = pq.top().second;
            int steps = pq.top().first;
            pq.pop();

            if(grid[r][c]=='#') return steps;

            if(vis[r][c]==1) continue;
            vis[r][c] = 1;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!='X'){
                    pq.push({steps+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};