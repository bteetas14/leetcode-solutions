class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n+1);

        for(auto it:times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, int>> q;
        vector<int> path(n+1, 1e9);
        // dist, node
        q.push({0, k});
        path[k] = 0;

        while(!q.empty()){
            auto [dist, node] = q.front();
            q.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(dist+adjDist < path[adjNode]){
                    q.push({dist+adjDist, adjNode});
                    path[adjNode] = dist+adjDist;
                }
            }
        }
        int maxTime = INT_MIN;
        for(int i=1;i<=n;i++){
            if(path[i]==1e9) return -1;
            maxTime = max(path[i], maxTime);
        }
        return maxTime;
    }
};