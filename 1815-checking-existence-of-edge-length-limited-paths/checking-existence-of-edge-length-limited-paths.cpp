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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        int q = queries.size();
        int e = edgeList.size();

        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }

        DisjointSet ds(n);

        sort(edgeList.begin(), edgeList.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });

        int edge = 0;
        vector<bool> ans(q);

        for(int i=0;i<q;i++){
            int q_u = queries[i][0];
            int q_v = queries[i][1];
            int limit = queries[i][2];
            int ind = queries[i][3];

            while(edge<e && edgeList[edge][2] < limit){
                int u = edgeList[edge][0];
                int v = edgeList[edge][1];
                int ewt = edgeList[edge][2];

                ds.unionByRank(u, v);
                edge++;
            }

            if(ds.findUParent(q_u) == ds.findUParent(q_v)){
                ans[ind] = true;
            }
            else{
                ans[ind] = false;
            }
        }
        return ans;
    }
};