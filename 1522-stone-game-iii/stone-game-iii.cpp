class Solution {
public:
    // int n;
    // int solve(int ind, vector<int>&stoneValue, vector<int>&dp){

    //     if(ind>=n) return 0;

    //     if(dp[ind]!=-1) return dp[ind];

    //     int stones = 0;
    //     int maxi = -1e9;

    //     for(int i=1;i<=3 && ind+i-1<n;i++){
    //         stones += stoneValue[ind+i-1];

    //         maxi = max(maxi, stones - solve(ind+i, stoneValue, dp));
    //     }
    //     return dp[ind] = maxi;
    // }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        vector<int> t(n+1);
        //t[i] = Alice - Bob
        
        for(int i = n-1; i>=0; i--) {
            
            t[i] = stoneValue[i] - t[i+1];
            
            if(i+2 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - t[i+2]);
        
            if(i+3 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - t[i+3]);
        
        }
        
        int diff = t[0];
        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
    }
};