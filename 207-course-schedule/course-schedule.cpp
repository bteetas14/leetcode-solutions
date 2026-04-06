class Solution {
public:
    bool canFinish(int t, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(t);
        vector<int> indegree(t, 0);
        queue<int> q;
        vector<int> topo;

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0;i<t;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo.size()==t;
    }
};