class Solution {
public:
    int solve(int ind, int buy, int count,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if (ind == prices.size()) return 0;
        if (count == 2) return 0;

        if (dp[ind][buy][count] != -1)
            return dp[ind][buy][count];

        int profit = 0;

        if (buy == 0) {
            // buy OR skip
            profit = max(
                -prices[ind] + solve(ind+1, 1, count, prices, dp),
                solve(ind+1, 0, count, prices, dp)
            );
        } else {
            // sell OR skip
            profit = max(
                prices[ind] + solve(ind+1, 0, count+1, prices, dp),
                solve(ind+1, 1, count, prices, dp)
            );
        }

        return dp[ind][buy][count] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );
        return solve(0, 0, 0, prices, dp);
    }
};
