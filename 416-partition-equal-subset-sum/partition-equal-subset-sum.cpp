class Solution {
public:
    bool solve(int ind, int target, vector<vector<int>>& dp, vector<int>& nums){

        if(target==0) return true;
        if(ind<0) return false;

        if(dp[ind][target] != -1) dp[ind][target];

        int take = false;
        if(nums[ind]<=target){
            take = solve(ind-1, target-nums[ind], dp, nums);
        }

        int notTake = solve(ind-1, target, dp, nums);

        return dp[ind][target]= take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for(auto it:nums){
            sum += it;
        }

        if(sum%2 != 0) return false;
        int target = sum/2;

        // vector<vector<int>> dp(n, vector<int>(target+1, -1)); 
        // return solve(n-1, target, dp, nums);

        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){

                bool take = false;
                if(nums[i]<=t){
                    take = dp[i-1][t-nums[i]];
                }

                bool notTake = dp[i-1][t];
                
                dp[i][t] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};