class Solution {
public:
    string alienOrder(vector<string>& words) {

        int n = words.size();
        unordered_map<char, vector<char>> mpp;
        unordered_map<char, int> indegree;

        for(auto it:words){
            for(auto c:it){
                indegree[c] = 0;
            }
        }

        for(int i=1;i<n;i++){
            string word1 = words[i-1];
            string word2 = words[i];

            if(word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";

            int w1=0, w2=0;
            while(w1<word1.size() && w2<word2.size()){
                if(word1[w1]==word2[w2]){
                    w1++;
                    w2++;
                }
                else{
                    mpp[word1[w1]].push_back(word2[w2]);
                    indegree[word2[w2]]++;
                    break;
                }
            }
        }

        queue<char> q;
        string result = "";
        for(auto it:indegree){
            if(it.second==0){
                q.push(it.first);
            }
        }

        while(!q.empty()){
            char c = q.front();
            q.pop();

            result += c;

            for(auto it:mpp[c]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(result.size() != indegree.size()) return "";
        return result;
    }
};