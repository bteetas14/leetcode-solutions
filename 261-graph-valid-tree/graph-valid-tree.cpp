class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& vis, int node, int parent){

        vis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                if(hasCycle(adj, vis, it, node)) return true;
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1) return false;

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(hasCycle(adj, vis, 0, -1)) return false;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                return false;
        }
        
        return true;
    }
};