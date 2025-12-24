class Solution {
public:
    int solve(int ind, int buy, vector<int> prices, vector<vector<int>>& dp){

        if(ind>=prices.size()) return 0;

        int profit = 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy==0){
            // buy
            profit = max(-prices[ind] + solve(ind+1, 1, prices, dp), solve(ind+1, 0, prices, dp));
        }
        else{
            // sell
            profit = max(prices[ind] + solve(ind+2, 0, prices, dp), solve(ind+1, 1, prices, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};