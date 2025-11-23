class Solution {
public:
    bool coloring(int node, int color, vector<vector<int>>& graph, vector<int>& vis){
        vis[node] = color;

        for(auto it:graph[node]){

            if(vis[it]!=-1 && vis[it]==color){
                return false;
            }

            if(vis[it]==-1){
                if(coloring(it, !color, graph, vis)==false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(coloring(i, 0, graph, vis)==false) return false;
            }
        }
        return true;
    }
};