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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();

        for (auto it: stones){
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);

        }

        DisjointSet ds(maxrow+ maxcol+1);

        unordered_map<int,int>stonenodes;

        for (auto it : stones){
            int noderow = it[0];
            int nodecol = it[1]+maxrow+1;
           ds.unionBySize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;

        }

        int cnt  = 0;

        for (auto it : stonenodes){
            if (ds.findUParent(it.first)==it.first){
                cnt++;
            }
        }

        return n-cnt;
    }
};