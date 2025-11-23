class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]==1) return true;
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i, adj, vis, pathVis)==true) return false;
            }
        }
        return true;
    }
};