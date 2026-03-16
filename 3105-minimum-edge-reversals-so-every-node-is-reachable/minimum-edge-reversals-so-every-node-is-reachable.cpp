class Solution {
public:
    int startNodeCost = 0;
    void dfs(int node, int parent, int d, vector<vector<pair<int, int>>>& adj, vector<int> &depth, vector<int> &vis, vector<int> &edgeRev){
        vis[node] = 1;
        depth[node] = d;

        for(auto it:adj[node]){
            if(vis[it.first]==false){
                edgeRev[it.first] = edgeRev[node] + it.second;
                startNodeCost += it.second;
                dfs(it.first, node, d+1, adj, depth, vis, edgeRev);
            }
        }

    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(n);
        vector<int> ans(n, 0);
        int startNode = -1;

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
            if(adj[u].size()==1){
                startNode = u;
            }
        }

        vector<int> depth(n, 0);
        vector<int> vis(n, 0);
        vector<int> edgeRev(n, 0);

        dfs(startNode, -1, 0, adj, depth, vis, edgeRev);
        ans[startNode] = startNodeCost;
        
        for(int i=0;i<n;i++){
            if(i==startNode){
                continue;
            }
            int v1 = depth[i] - edgeRev[i];
            int v2 = startNodeCost - edgeRev[i];
            ans[i] = v1 + v2;
        }
        return ans;
    }
};