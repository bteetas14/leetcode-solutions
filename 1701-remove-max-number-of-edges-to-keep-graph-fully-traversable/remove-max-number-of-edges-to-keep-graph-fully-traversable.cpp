class DisjointSet{
public:
    vector<int> parent, rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(parent[node] == node){
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
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DisjointSet alice(n), bob(n);
        int removed = 0;

        // Step 1: process type 3 edges first
        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b){
                 return a[0] > b[0];
             });

        for(auto &e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 3){
                bool a = alice.findUParent(u) != alice.findUParent(v);
                bool b = bob.findUParent(u) != bob.findUParent(v);

                if(a) alice.unionByRank(u, v);
                if(b) bob.unionByRank(u, v);

                if(!a && !b) removed++;
            }
            else if(type == 1){
                if(alice.findUParent(u) != alice.findUParent(v))
                    alice.unionByRank(u, v);
                else
                    removed++;
            }
            else{
                if(bob.findUParent(u) != bob.findUParent(v))
                    bob.unionByRank(u, v);
                else
                    removed++;
            }
        }

        // Step 3: check connectivity
        int aComp = 0, bComp = 0;
        for(int i = 1; i <= n; i++){
            if(alice.findUParent(i) == i) aComp++;
            if(bob.findUParent(i) == i) bComp++;
        }

        if(aComp != 1 || bComp != 1) return -1;
        return removed;
    }
};