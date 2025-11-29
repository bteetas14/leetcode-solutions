class DisjointSet{
public:
    vector<int> rank, parent, sizes;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);

        if(ulp_v == ulp_u) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);

        if(ulp_v == ulp_u) return;

        if(sizes[ulp_u] > sizes[ulp_v]){
            parent[ulp_v] = ulp_u;
            sizes[ulp_u] += sizes[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            sizes[ulp_v] += sizes[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailParentMap;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mailParentMap.find(accounts[i][j]) == mailParentMap.end()){
                    mailParentMap[accounts[i][j]] = i;
                }
                else{
                    int pNode = mailParentMap[accounts[i][j]];
                    ds.unionBySize(pNode, i);
                }
            }
        }

        vector<vector<string>> mailMap(n);
        for(auto it: mailParentMap){
            string mail = it.first;
            int prnt = ds.findUParent(it.second);

            mailMap[prnt].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mailMap[i].empty()) continue;
            sort(mailMap[i].begin(), mailMap[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mailMap[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};