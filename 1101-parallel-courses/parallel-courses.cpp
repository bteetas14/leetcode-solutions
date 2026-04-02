class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {

        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1, 0);
        queue<int> q;
        vector<int> topo;
        int sems = 0;

        for(auto it:relations){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indeg[v]++;
        }
        
        for(int i=1;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz-->0){
                int ele = q.front();
                q.pop();

                topo.push_back(ele);

                for(auto it:adj[ele]){
                    indeg[it]--;
                    if(indeg[it]==0){
                        q.push(it);
                    }
                }
            }
            sems++;
        }
        if(sems==0 || topo.size()!=n) return -1;
        return sems;
    }
};