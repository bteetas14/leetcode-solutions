class Solution {
public:
    int solve(int ind, int amount, vector<vector<int>>& dp, vector<int>& coins){

        if(amount==0) return 1;

        if(ind<0){
            // if(coins[0]==amount) return 1;
            return 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int take = 0;
        if(coins[ind]<=amount){
            take = solve(ind, amount-coins[ind], dp, coins);
        }

        int notTake = solve(ind-1, amount, dp, coins);

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, dp, coins);
        
    }
};