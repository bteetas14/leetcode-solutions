class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjMat){

        vis[node] = 1;

        for(auto it:adjMat[node]){
            if(vis[it]==0){
                dfs(it, vis, adjMat);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adjMat(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjMat[i].push_back(j);
                    adjMat[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, vis, adjMat);
            }
        }
        return cnt;
    }
};