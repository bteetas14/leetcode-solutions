class Solution {
public:
    bool solve(int i, string &s, unordered_set<string> &dict, vector<int> &dp){

        if(i == s.size()){
            return true; // succesfully the word is broken
        }

        if(dp[i]!= -1) return dp[i];

        string word = "";

        for(int j=i;j<s.size();j++){
            word += s[j];

            if(dict.count(word) > 0){
                if(solve(j+1, s, dict, dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = 0;
    }


    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<int> dp(n, -1);
        return solve(0, s, dict, dp);
        
    }
};