class DisjointSet{
public:
    vector<int> rank, sizes, parent;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        sizes.resize(n+1, 1);
        parent.resize(n+1);
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

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

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
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        // vector<vector<int>> adj(n+1);
        DisjointSet ds(n);

        // for(auto it:edges){
        //     int u = it[0];
        //     int v = it[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        vector<int> ans;
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUParent(u) == ds.findUParent(v)){
                ans = {u, v};
                break;
            }

            ds.unionBySize(u, v);
        }
        return ans;
    }
};