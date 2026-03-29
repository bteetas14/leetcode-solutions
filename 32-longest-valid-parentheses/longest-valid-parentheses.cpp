class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // base index

        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.empty()){
                    st.push(i);  // reset base
                }
                else{
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
    // bool isValidP(int start, int end, string& s){
    //     stack<char> st;
    //     for(int i=start;i<=end;i++){
    //         if(s[i]=='('){
    //             st.push(s[i]);
    //         }
    //         else{
    //             if(st.empty()) return false;
    //             if(st.top()=='(') st.pop();
    //         }
    //     }
    //     return st.size()==0;
    // }
    // int solve(int ind, string& s, vector<int>& dp){

    //     int n = s.size();
    //     if(ind>=n) return 0;
    //     int maxi = -1e9;

    //     if(dp[ind]!=-1) return dp[ind];

    //     int notTake = solve(ind+1, s, dp);

    //     for(int i=ind;i<n;i++){
    //         if(isValidP(ind, i, s)){
    //             int len = i-ind+1;
    //             maxi = max(len, maxi);
    //             // maxi = max(maxi, len+solve(i+1, s));
    //         }
    //     }
    //     return dp[ind] = max(notTake, maxi);
    // }

    // int longestValidParentheses(string s) {

    //     vector<int> dp(s.size(), -1);
    //     return solve(0, s, dp);
        
    // }
};
