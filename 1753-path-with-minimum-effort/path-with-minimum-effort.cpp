class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n , vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 0});
        // vis[0][0] = 1;

        while(!pq.empty()){
            auto [eff, r, c] = pq.top();
            pq.pop();

            if (vis[r][c]) continue;
            vis[r][c] = 1;   

            if(r==n-1 && c==m-1) return eff;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){

                    int newEff = max(eff, abs(heights[r][c]-heights[nrow][ncol]));
                    pq.push({newEff, nrow, ncol});
                    // vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};