class Solution {
public:
    bool isValid(int nrow, int ncol, vector<vector<int>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();

        return (nrow<n && nrow>=0 && ncol<m && ncol>=0);
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int totOranges = 0, totMinutes = 0, rottenOranges = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j] = 1;
                    rottenOranges++;
                }
                if(grid[i][j]==1) totOranges++;
            }
        }

        if(totOranges==0 && rottenOranges==0) return 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int size = q.size();
            totMinutes++;

            for(int i=0;i<size;i++){
                auto [row, col] = q.front();
                q.pop();

                for(int x=0;x<4;x++){
                    int nrow = row + drow[x];
                    int ncol = col + dcol[x];

                    if(isValid(nrow, ncol, grid)==true && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                        totOranges--;
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        if(totOranges>0) return -1;
        return totMinutes-1;
    }
};