class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> path(n, vector<int>(m,1e9));

        queue<pair<int, pair<int, int>>> q;
        q.push({0,{0, 0}});
        path[0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int diff = q.front().first;
            auto [r, c] = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int eff = max(diff, abs(heights[nrow][ncol] - heights[r][c]));

                    if(eff < path[nrow][ncol]){
                        q.push({eff, {nrow, ncol}});
                        path[nrow][ncol] = eff;
                    }
                }
            }
        }
        return path[n-1][m-1];
    }
};