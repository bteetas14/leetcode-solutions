class Solution {
public:
    int n;
    vector<int> prefix;
    vector<int> dp;

    int solve(int i){
        if(i == n-1) return prefix[i];
        if(dp[i] != -1) return dp[i];

        int skip = solve(i+1);
        int take = prefix[i] - solve(i+1);

        return dp[i] = max(skip, take);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();

        // build prefix sum
        prefix.resize(n);
        prefix[0] = stones[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + stones[i];
        }

        dp.resize(n, -1);

        return solve(1);  // start from index 1 (since x ≥ 2)
    }
};