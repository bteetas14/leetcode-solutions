// class Solution {
// public:
//     bool solve(int ind, int k, vector<int>& dp, vector<int>& stones, map<int, int>& mpp){
        
//         int n = stones.size();

//         if(ind == n-1) return true;

//         if(dp[ind] != -1) return dp[ind];

//         bool kMinus1 = false;
//         if(mpp.find(stones[ind]+(k-1)) != mpp.end() && mpp[stones[ind] + (k-1)] > ind){
//             int newIndex = mpp[stones[ind] + (k-1)];
//             kMinus1 = solve(newIndex, k-1, dp, stones, mpp);
//         }

//         bool kSame = false;
//         if(mpp.find(stones[ind]+k) != mpp.end() && mpp[stones[ind] + k] > ind){
//             int newIndex = mpp[stones[ind] + k];
//             kSame = solve(newIndex, k, dp, stones, mpp);
//         }

//         bool kPlus = false;
//         if(mpp.find(stones[ind]+(k+1)) != mpp.end() && mpp[stones[ind] + (k+1)] > ind){
//             int newIndex = mpp[stones[ind] + (k+1)];
//             kPlus = solve(newIndex, k+1, dp, stones, mpp);
//         }

//         return dp[ind] = kMinus1 || kSame || kPlus;
//     }

//     bool canCross(vector<int>& stones) {

//         int n = stones.size();
//         map<int, int> mpp;

//         for(int i=0;i<n;i++){
//             mpp[stones[i]] = i;
//         }

//         vector<int> dp(n, -1);
//         return solve(0, 1, dp, stones, mpp);
//     }
// };
class Solution {
public:
    bool solve(int ind, int k, vector<int>& stones, map<int,int>& mpp, map<pair<int,int>, bool>& dp){
        int n = stones.size();
        if(ind == n-1) return true;

        if(dp.count({ind,k})) return dp[{ind,k}];

        bool res = false;
        for(int jump = k-1; jump <= k+1; jump++){
            if(jump <= 0) continue;
            int target = stones[ind] + jump;
            if(mpp.find(target) != mpp.end()){
                int newIndex = mpp[target];
                res |= solve(newIndex, jump, stones, mpp, dp);
            }
        }

        return dp[{ind,k}] = res;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;  // first jump must be 1
        int n = stones.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[stones[i]] = i;

        map<pair<int,int>, bool> dp;
        return solve(1, 1, stones, mpp, dp);  // start from index 1
    }
};
