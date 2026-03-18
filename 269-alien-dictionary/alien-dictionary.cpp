class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, set<char>> adjMap;
        unordered_map<char, int> indegree;
        queue<char> q;
        string ans = "";

        for(auto word : words){
            for(char c : word){
                indegree[c] = 0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for(int j=0;j<len;j++){
                if(w1[j] != w2[j]){
                    if(adjMap[w1[j]].count(w2[j]) == 0){
                        adjMap[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }

            if(!found && w1.size() > w2.size()){
                return "";
            }
        }

        for(auto it:indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }

        while(!q.empty()){
            char c = q.front();
            q.pop();

            ans += c;

            for(auto it:adjMap[c]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(ans.size() != indegree.size()){
            return "";
        }
        
        return ans;
    }
};