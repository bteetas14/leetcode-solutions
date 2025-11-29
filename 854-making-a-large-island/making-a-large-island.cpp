class DisjointSet{
public:
    vector<int> rank, parent, sizes;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);

        if(ulp_v == ulp_u) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);

        if(ulp_v == ulp_u) return;

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
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);

        vector<pair<int, int>> zeroes;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    zeroes.push_back({i,j});
                    continue;
                }
                
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                            if(ds.findUParent(i*m + j) != ds.findUParent(nrow*m + ncol)){
                                ds.unionBySize(i*m + j, nrow*m + ncol);
                            }
                        }
                    }
                }
            }
        }
        if(zeroes.size()==0) return n*m;

        // from here
        int maxSize = 0;

        for(auto it : zeroes){
            int zrow = it.first;
            int zcol = it.second;

            unordered_set<int> seen;   // FIX 1

            for(int i=0;i<4;i++){
                int nrow = zrow + delrow[i];
                int ncol = zcol + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    int ulp = ds.findUParent(nrow*m + ncol);
                    seen.insert(ulp);
                }
            }

            int tempSize = 1;
            for(int p : seen) tempSize += ds.sizes[p];

            maxSize = max(maxSize, tempSize);
        }

        // FIX 2 — Check original island sizes
        for(int cell = 0; cell < n*m; cell++){
            maxSize = max(maxSize, ds.sizes[ds.findUParent(cell)]);
        }

        return maxSize;
    }
};