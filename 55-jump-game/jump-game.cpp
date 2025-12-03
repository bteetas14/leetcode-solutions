class Solution {
public:
    bool solve(int ind , vector<int>& nums, vector<int>&dp){
        int n = nums.size();

        if(ind==n-1) return true;
        if(ind>n-1) return false;

        if(dp[ind]!=-1) return dp[ind];

        bool ans = false;
        for(int i=1;i<=nums[ind] && ind+i<=n-1;i++){
            bool jump = solve(ind+i, nums, dp);
            ans = ans || jump;
        }
        return dp[ind] = ans;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();

        // vector<int> dp(n, -1);

        // return solve(0, nums, dp);

        vector<bool> dp(n+1, -1);

        dp[n] = false;
        dp[n-1] = true;

        for(int ind=n-2;ind>=0;ind--){

            bool ans = false;

            for(int i=1;i<=nums[ind] && ind+i<=n-1;i++){
                bool jump = dp[ind+i];
                ans = ans || jump;
            }

            dp[ind] = ans;
        }
        return dp[0];
        
    }
};