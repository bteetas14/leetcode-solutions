class Solution {
public:
    bool dfs(int node, int t, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it, t, vis, pathVis, adj)) return true;
            }
            else if(pathVis[it]==1){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int t, vector<vector<int>>& prerequisites) {

        vector<int> vis(t, 0);
        vector<int> pathVis(t, 0);
        vector<vector<int>> adj(t);

        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0;i<t;i++){
            if(vis[i]==0){
                if(dfs(i, t, vis, pathVis, adj)==true) return false;
            }
        }
        return true;
    }
};