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
    int makeConnected(int n, vector<vector<int>>& connections) {

        // sort(connections.begin(), connections.end());

        DisjointSet ds(n);
        int extras = 0;

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            if(ds.findUParent(u) != ds.findUParent(v))
                ds.unionByRank(u, v);
            else
                extras++; // extra cable
        }

        int freeParents = 0;
        for(int i=0;i<n;i++){
            if(ds.findUParent(i)==i){
                freeParents++;
            }
        }

        int numberOfEdgesRequired = freeParents - 1;
        if(numberOfEdgesRequired <= extras){
            return numberOfEdgesRequired;
        }
        return -1;
    }
};
