class Solution {
public:
    bool solve(int ind, string s, unordered_set<string>& st, vector<int>& dp){

        int n = s.size();
        if(ind>n-1) return false;

        if(dp[ind] != -1) return dp[ind];

        if(st.count(s.substr(ind,n-ind))>0) return dp[ind] = true;

        for(int i=ind;i<n;i++){
            string sub = s.substr(ind, i-ind+1);

            if(st.count(sub)>0){
                if(solve(i+1, s, st, dp)==true) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);

        return solve(0, s, st, dp);
        // return dp[n-1];
    }
};