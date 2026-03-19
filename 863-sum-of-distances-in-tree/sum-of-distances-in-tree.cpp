class Solution {
public:
    int result_base_node = 0;
    vector<int> count;

    int dfsBase(vector<vector<int>>& adj, int curr_node, int prev_node, int curr_depth){
        int total_nodes = 1;
        
        result_base_node += curr_depth;

        for(auto it:adj[curr_node]){
            if(it==prev_node){
                continue;
            }
            total_nodes += dfsBase(adj, it, curr_node, curr_depth+1);
        }
        count[curr_node] = total_nodes;
        return total_nodes;
    }

    void dfs(vector<vector<int>>& adj, int curr_node, int prev_node, vector<int>& result){
        
        for(auto child: adj[curr_node]){
            if(child==prev_node){
                continue;
            }
            result[child] = result[curr_node] - count[child] + (adj.size()-count[child]);
            dfs(adj, child, curr_node, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        count.resize(n,0);

        dfsBase(adj, 0, -1, 0);

        vector<int> result(n);
        result[0] = result_base_node;

        dfs(adj, 0, -1, result);
        return result;
    }
};