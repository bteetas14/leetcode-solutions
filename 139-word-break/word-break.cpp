class Solution {
public:
    bool solve(int ind, string fullWord, vector<string>& wordDict, unordered_set<string> st, vector<int>& dp){
        
        int n = fullWord.size();

        if(ind>n-1) return true;

        if(dp[ind] != -1) return dp[ind];

        if(st.count(fullWord.substr(ind, n-ind))>0) return dp[ind] = true;

        for(int i=ind;i<n;i++){
            // present
            string sub = fullWord.substr(ind, i-ind+1);

            if(st.count(sub) > 0){
                if(solve(i+1, fullWord, wordDict, st, dp) == true) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string fullWord, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(fullWord.size(), -1);

        return solve(0, fullWord, wordDict, st, dp);
        
    }
};