class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1) return {0};

        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(n>2){
            int size = q.size();
            n -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
        }
        return result;
    }
};