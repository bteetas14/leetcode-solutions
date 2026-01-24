class Solution {
public:
    int solve(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp){

        if(ind==nums.size()) return 0;

        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

        // not take
        int notTake = solve(ind+1, prevInd, nums, dp);

        // take
        int take = -1e9;
        if(prevInd==-1 || nums[ind] > nums[prevInd]){
            take = 1 + solve(ind+1, ind, nums, dp);
        }

        return dp[ind][prevInd+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, nums, dp);

        // tabulation

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){

                int notTake = dp[ind+1][prevInd+1];

                int take = 0;
                if(prevInd==-1 || nums[ind] > nums[prevInd]){
                    take = 1 + dp[ind+1][ind+1];
                }

                dp[ind][prevInd+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};