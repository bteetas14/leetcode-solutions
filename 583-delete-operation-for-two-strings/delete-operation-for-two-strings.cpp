class Solution {
public:
    int solve(int n1, int n2, string word1, string word2, vector<vector<int>> &dp){
        if(n1<0 || n2<0) return 0;

        if(dp[n1][n2]!=-1) return dp[n1][n2];

        if(word1[n1]==word2[n2]){
            return dp[n1][n2] = 1 + solve(n1-1, n2-1, word1, word2, dp);
        }

        int right = solve(n1-1, n2, word1, word2, dp);
        int left = solve(n1, n2-1, word1, word2, dp);

        return dp[n1][n2] = max(left, right);
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        int maxLen = solve(n-1, m-1, word1, word2, dp);
        return n+m - 2*maxLen;
    }
};