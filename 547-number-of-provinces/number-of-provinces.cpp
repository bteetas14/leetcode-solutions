class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){

        vis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};