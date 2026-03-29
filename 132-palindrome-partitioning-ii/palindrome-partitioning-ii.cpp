class Solution {
public:
    bool checkPalidrome(int start, int end, string& s){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int f(int ind, string& s, vector<int>& dp){
        if(ind>=s.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int mini = 1e9;
        for(int i=ind;i<s.size();i++){
            if(checkPalidrome(ind, i, s)){
                mini = min(mini, f(i+1, s, dp));
            }
        }
        return dp[ind] = 1+mini;
    }
    int minCut(string s) {

        if(s.size()==1) return 0;

        vector<int> dp(s.size(), -1);
        return f(0, s, dp)-1;
    }
};