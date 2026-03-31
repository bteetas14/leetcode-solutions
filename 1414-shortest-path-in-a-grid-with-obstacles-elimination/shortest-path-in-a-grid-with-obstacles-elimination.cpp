class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> bestK(n, vector<int>(m, -1));
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>, 
            greater<pair<int, vector<int>>>> pq;
        pq.push({0, {0, 0, k}});

        while(!pq.empty()){
            auto p = pq.top().second;
            int r = p[0], c = p[1], obs = p[2];
            int steps = pq.top().first;
            pq.pop();

            if(r==n-1 && c==m-1) return steps;

            if(bestK[r][c]>=obs) continue;
            bestK[r][c] = obs;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newK = obs;
                    if(grid[nrow][ncol]==1){
                        newK--;
                    }
                    if(newK >= 0){
                        pq.push({steps+1, {nrow, ncol, newK}});
                    }
                }
            }
        }
        return -1;
    }
};