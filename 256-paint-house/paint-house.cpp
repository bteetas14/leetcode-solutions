class Solution {
public:
    int n, m;

    int solve(int house, int prevColor, vector<vector<int>>& costs, vector<vector<int>>& dp){
        if(house == n-1){
            return 0;
        }
        int minCost = 1e9;

        if(dp[house][prevColor] != -1) return dp[house][prevColor];

        for(int clr=0;clr<3;clr++){
            if(prevColor != clr){
                minCost = min(minCost, costs[house+1][clr] + solve(house+1, clr, costs, dp));
            }
        }
        return dp[house][prevColor] = minCost;
    }

    int minCost(vector<vector<int>>& costs) {

        n = costs.size();
        m = 3;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        // 0 - red, 1 - blue, 2 - green

        int red = costs[0][0] + solve(0, 0, costs, dp);
        int blue = costs[0][1] + solve(0, 1, costs, dp);
        int green = costs[0][2] + solve(0, 2, costs, dp);

        int mini = 1e9;
        mini = min(blue, red);
        mini = min(mini, green);
        
        return mini;
    }
};