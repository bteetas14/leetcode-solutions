class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int> vis(n, 0);

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        pq.push({0, 0});
        int edgesUsed = 0;
        int totalCost = 0;

        while(edgesUsed < n){
            auto [cost, node] = pq.top();
            pq.pop();

            if(vis[node]==1) continue;

            vis[node] = 1;
            totalCost += cost;
            edgesUsed++;

            for(int i=0;i<n;i++){
                if(i==node) continue;

                if(vis[i]==0){

                    int distn = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                    pq.push({distn, i});

                }
            }
        }
        return totalCost;
    }
};
