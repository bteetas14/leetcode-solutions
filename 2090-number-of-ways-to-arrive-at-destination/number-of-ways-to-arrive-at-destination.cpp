class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);
        const long long MOD = 1e9 + 7;

        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> ways(n, 0);
        // dist, node
        vector<long long> path(n, LLONG_MAX);
        q.push({0, 0});
        path[0] = 0;
        ways[0] = 1;

        while(!q.empty()){
            auto [dist, node] = q.top();
            q.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(dist + adjDist < path[adjNode]){
                    path[adjNode] = dist + adjDist;
                    ways[adjNode] = ways[node];
                    q.push({dist+adjDist, adjNode});
                }
                else if (dist + adjDist == path[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};