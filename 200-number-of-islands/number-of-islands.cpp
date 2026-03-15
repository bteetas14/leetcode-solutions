class DisjointSet{
public:
    vector<int> parent, sizes;

    DisjointSet(int n){
        parent.resize(n+1);
        sizes.resize(n+1, 0);

        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(sizes[ulp_u] > sizes[ulp_v]){
            parent[ulp_v] = ulp_u;
            sizes[ulp_u] += sizes[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            sizes[ulp_v] += sizes[ulp_u];
        }
    }
};

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, DisjointSet &ds){

        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                int ulp_next = ds.findUParent(nrow*m + ncol);
                int ulp_curr = ds.findUParent(row*m + col);

                if(ulp_next != ulp_curr){
                    ds.unionBySize(nrow*m + ncol, row*m + col);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int numIslands = 0;
        DisjointSet ds(n*m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i, j, grid, vis, ds);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && ds.findUParent(i*m+j)==(i*m+j)){
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};

// 
// i, j
// (i)*m + j