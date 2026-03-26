class Solution {
public:
    int solve(int start, int end, vector<int>& prefixSum, vector<int>& stones, vector<vector<int>>& dp){
        if(start==end) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        int removeLeftmost = (prefixSum[end] - prefixSum[start]) - solve(start+1, end, prefixSum, stones, dp);
        int removeRightmost = (prefixSum[end-1] - (start>0?prefixSum[start-1]:0)) - solve(start, end-1, prefixSum, stones, dp);

        return dp[start][end] = max(removeLeftmost, removeRightmost);
    }

    int stoneGameVII(vector<int>& stones) {

        int n = stones.size();
        vector<int> prefixSum(n);

        prefixSum[0] = stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, n-1, prefixSum, stones, dp);
    }
};