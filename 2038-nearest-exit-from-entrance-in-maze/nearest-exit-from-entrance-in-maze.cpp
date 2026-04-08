class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        queue<pair<pair<int, int>, int>> q;
        // r c steps

        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]] = 1;
        int ans = -1;

        while(!q.empty()){
            auto [r, c] = q.front().first;
            int steps = q.front().second;
            q.pop();

            if((r==0 || r==n-1 || c==0 || c==m-1) && (r!=entrance[0] || c!=entrance[1])){
                ans = steps;
                break;
            }

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && maze[nrow][ncol]=='.'){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return ans;
    }
};