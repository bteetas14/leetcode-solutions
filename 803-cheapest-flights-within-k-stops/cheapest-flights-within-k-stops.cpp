class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> path(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        // stops, node, dist
        q.push({0, {src, 0}});
        path[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            auto [node, dist] = q.front().second;
            q.pop();

            if(stops>k) continue;

            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjNodeDist = it.second;

                if(dist + adjNodeDist < path[adjNode]){
                    path[adjNode] = dist + adjNodeDist;
                    q.push({stops+1, {adjNode, dist+adjNodeDist}});
                }
            }
        }
        if(path[dest]==1e9) return -1;
        return path[dest];
    }
};