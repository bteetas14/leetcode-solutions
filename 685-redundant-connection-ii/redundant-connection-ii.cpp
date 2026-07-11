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

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(sizes[ulp_u]>sizes[ulp_v]){
            parent[ulp_v] = ulp_u;
            sizes[ulp_u] += sizes[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            sizes[ulp_v] += sizes[ulp_u];
        }
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        DisjointSet ds(n);

        vector<int> directParent(n+1, 0);
        vector<int> first, second;

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(directParent[v]==0){
                directParent[v]=u;
            }
            else{
                first = {directParent[v], v};
                second = edge;
            }
        }

        for(auto &edge:edges){

            if(edge==second) continue;

            int u = edge[0];
            int v = edge[1];

            if(ds.findUParent(u) == ds.findUParent(v)){

                if(first.empty()) return edge;
                
                return first;
            }
            ds.unionBySize(u, v);
        }
        return second;
    }
};