class DisjointSet{
    vector<int> parent, sizes;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        sizes.resize(n+1, 1);

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
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {

        DisjointSet ds(n);

        sort(logs.begin(), logs.end());
        int components = n;

        int time;
        for(auto it:logs){
            int time = it[0];
            int u = it[1];
            int v = it[2];

            if(ds.findUParent(u) != ds.findUParent(v)){
                ds.unionBySize(u, v);
                components--;
                if(components==1) return time;
            }
        }
        return -1;
    }
};