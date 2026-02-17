class Solution {
public:
    long solve(int ind, int buy, vector<int>&prices, vector<vector<long>>&dp){
        if(ind==prices.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int cost = 0;

        if(buy==0){
            cost = max((-prices[ind] + solve(ind+1, 1, prices, dp)), solve(ind+1, 0, prices, dp));
        }
        else{
            cost = max((prices[ind] + solve(ind, 0, prices, dp)), solve(ind+1, 1, prices, dp));
        }
        return dp[ind][buy] = cost;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long>(2, -1));

        return solve(0, 0, prices, dp);
    }
};