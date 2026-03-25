class Solution {
public:
    int n;

    long long solveAlice(int player, int ind, int m, vector<int>&piles, vector<vector<vector<int>>>&dp){

        if(ind>=n) return 0;

        if(dp[player][ind][m]!=-1) return dp[player][ind][m];

        long long result;
        long long stones = 0;

        if(player==1) result = -1e9;
        else result = 1e9;

        for(int i=1;i<=min(2*m, n-ind);i++){
            stones += piles[ind+i-1];

            if(player==1){
                result = max(result, stones + solveAlice(0, ind+i, max(m,i), piles, dp));
            }
            else{
                result = min(result, solveAlice(1, ind+i, max(m,i), piles, dp));
            }
        }
        return dp[player][ind][m] = result;
    }

    int stoneGameII(vector<int>& piles) {
        
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        return solveAlice(1, 0, 1, piles, dp);
    }
};