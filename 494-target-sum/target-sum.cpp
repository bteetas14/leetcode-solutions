// class Solution {
// public:
//     int solve(int ind, int target, vector<vector<int>>& dp, vector<int>& arr){

//         if(ind==0){
//             if(target==0 && arr[0]==0) return 2;
//             if(target==0) return 1;
//             if(arr[0]==target) return 1;
//             return 0;
//         }

//         if(dp[ind][target] != -1) return dp[ind][target];

//         int take = 0;
//         if(arr[ind] <= target){
//             take = solve(ind-1, target-arr[ind], dp, arr);
//         }

//         int notTake = solve(ind-1, target, dp, arr);

//         return dp[ind][target] = take + notTake;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {

//         int n = nums.size();

//         int sum = 0;
//         for(auto it:nums){
//             sum += it;
//         }

//         if((sum + target) % 2 != 0) return 0;

//         int k = (target+sum)/2;
//         vector<vector<int>> dp(n, vector<int>(k+1, -1));

//         return solve(n-1, k, dp, nums);
//     }
// };
class Solution {
public:

    int f(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        if (index==0) {
            if (target==0 && nums[index]==0) return 2;
            if (nums[index]==target || target==0) return 1;
            return 0;
        }
        
        if(dp[index][target]!=-1) return dp[index][target];
        
        int Pick=0;
        if (nums[index]<=target) Pick=f(index-1, target-nums[index], nums, dp);
        
        int notPick=f(index-1, target, nums, dp);

        return dp[index][target] = Pick+notPick;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int k=(sum-target);
        if (k<0 || k%2!=0){
            return 0;
        }

        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return f(n-1, k/2, nums, dp);

    }
};