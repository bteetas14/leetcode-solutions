class Solution {
public:
    int n;
    int solve(int ind, vector<int>&stoneValue, vector<int>&dp){

        if(ind>=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int stones = 0;
        int maxi = -1e9;

        for(int i=1;i<=3 && ind+i-1<n;i++){
            stones += stoneValue[ind+i-1];

            maxi = max(maxi, stones - solve(ind+i, stoneValue, dp));
        }
        return dp[ind] = maxi;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();
        vector<int> dp(n+1, -1);

        int diff = solve(0, stoneValue, dp);
        
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        return "Tie";
    }
};