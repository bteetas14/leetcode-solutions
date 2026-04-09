class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source==target) return 0;

        unordered_map<int, vector<int>> adjMap;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                adjMap[it].push_back(i);
            }
        }

        set<int> visBuses;
        queue<int> q;
        for(auto buses:adjMap[source]){
            q.push(buses);
            visBuses.insert(buses);
        }

        int busesTaken = 1;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int bus = q.front();
                q.pop();

                for(auto stop:routes[bus]){
                    if(target==stop){
                        return busesTaken;
                    }
                    for(auto b:adjMap[stop]){
                        if(visBuses.count(b)==0){
                            q.push(b);
                            visBuses.insert(b);
                        }
                    }
                }
            }
            busesTaken++;
        }
        return -1;
    }
};