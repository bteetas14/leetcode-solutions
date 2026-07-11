class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<vector<int>>&ans, vector<int>&temp){
        temp.push_back(node);

        if(node==adj.size()-1){
            ans.push_back(temp);

            temp.pop_back();
            return;
        }

        for(auto it:adj[node]){
            dfs(it, adj, ans, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {

        int n = adj.size();
        int source = 0, target = n-1;

        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(0, adj, ans, temp);
        return ans;        
    }
};