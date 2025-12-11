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

    int change(int T, vector<int>& arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(T + 1, 0));
        long long MOD = 1e15;

        // Initializing base condition
        for (int i = 0; i <= T; i++) {
            if (i % arr[0] == 0)
                dp[0][i] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= T; target++) {
                long long notTaken = dp[ind - 1][target];

                long long taken = 0;
                if (arr[ind] <= target)
                    taken = dp[ind][target - arr[ind]];

                dp[ind][target] = notTaken + taken;
                dp[ind][target] %= MOD;
            }
        }

        return dp[n - 1][T];
    }
};