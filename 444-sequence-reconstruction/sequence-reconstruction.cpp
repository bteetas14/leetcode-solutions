class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& seq) {

        vector<int> indegree(nums.size()+1);
        vector<vector<int>> adj(nums.size()+1);
        vector<int> topo;

        queue<int> q;
        for(auto it:seq){
            for(int i=1;i<it.size();i++){
                indegree[it[i]]++;
                adj[it[i-1]].push_back(it[i]);
            }
        }

        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            if(q.size()>1) return false;

            int ele = q.front();
            q.pop();

            topo.push_back(ele);

            for(auto it:adj[ele]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo == nums;
    }
};