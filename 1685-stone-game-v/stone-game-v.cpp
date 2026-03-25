class Solution {
public:
    unordered_map<int, int> prefixSum;
    int n;

    int solve(int start, int end, vector<int>& stoneValue, vector<vector<int>>& dp){
        if(end==start) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        int maxi = -1e9;

        for(int i=start;i<end;i++){
            int lsum = prefixSum[i] - (start > 0 ? prefixSum[start-1] : 0);
            int rsum = prefixSum[end] - prefixSum[i];

            if(lsum>rsum){
                maxi = max(maxi, rsum + solve(i+1, end, stoneValue, dp));
            }
            else if(rsum>lsum){
                maxi = max(maxi, lsum + solve(start, i, stoneValue, dp));
            }
            else{
                maxi = max(maxi, max(rsum + solve(i+1, end, stoneValue, dp), rsum + solve(start, i, stoneValue, dp)));
            }
        }
        return dp[start][end] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {

        n = stoneValue.size();
        int preSum = 0;
        prefixSum[0] = stoneValue[0];

        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + stoneValue[i];
        }

        // prefixSum[-1] = 0;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n-1, stoneValue, dp);
        
    }
};