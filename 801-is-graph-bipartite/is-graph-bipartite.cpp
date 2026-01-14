class Solution {
public:
    bool solve(int node, int color, vector<int>& colorMat, vector<vector<int>>& adj){

        colorMat[node] = color;

        for(auto it:adj[node]){
            if(colorMat[it]==color){
                return false;
            }
            else if(colorMat[it]==-1){
                if(solve(it, !color, colorMat, adj)==false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> colorMat(n, -1);
        for(int i = 0; i < n; i++){
        if(colorMat[i] == -1){
            if(!solve(i, 0, colorMat, adj))
                return false;
            }
        }
        return true;
    }
};