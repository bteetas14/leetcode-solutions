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
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

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
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

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

        unordered_map<string, int> mailMapParent;
        int n = accounts.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string acc = accounts[i][j];

                if(mailMapParent.find(acc) == mailMapParent.end()){
                    mailMapParent[acc] = i;
                }
                else{
                    int pNode = mailMapParent[acc];
                    ds.unionByRank(pNode, i);
                }
            }
        }

        vector<vector<string>> emails(n);
        for(auto it:mailMapParent){
            string mail = it.first;
            int parent = ds.findUParent(it.second);

            emails[parent].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(emails[i].empty()) continue;
            sort(emails[i].begin(), emails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: emails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};