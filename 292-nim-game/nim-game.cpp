class Solution {
public:
    bool solve(int n, vector<int>& dp){
        if(n==0) return false;

        if(dp[n]!=-1) return dp[n];

        for(int i=1;i<=3 && (n-i)>=0;i++){
            if(!solve(n-i, dp)){
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
    bool canWinNim(int n) {

        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        // vector<bool> dp(n+1, false);
        
        // for(int i=1;i<=n;i++){
        //     for(int c=1;c<=3 && (i-c)>=0;c++){
        //         if(!dp[i-c]){
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[n];

        return n % 4 != 0;

    }
};