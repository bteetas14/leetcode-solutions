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
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solve(0, -1, nums, dp);
    }
};