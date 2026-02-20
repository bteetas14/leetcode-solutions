class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp, int n){
        if(ind==n-1) return 0;
        if(ind>n-1) return 1e9;

        if(dp[ind]!=-1) return dp[ind];

        int minJumps = 1e9;
        for(int i=1;i<=nums[ind];i++){
            minJumps = min(minJumps, 1 + solve(ind+i, nums, dp, n));
        }
        return dp[ind] = minJumps;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp, n);
    }
};