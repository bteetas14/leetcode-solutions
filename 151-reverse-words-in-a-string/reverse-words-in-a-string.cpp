class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        stack<char> st;
        string ans = "";
        int i;

        for(i=n-1;i>=0;i--){
            if(s[i]!=' '){
                st.push(s[i]);
            }
            else{          // ==' '
                if(!st.empty()){
                    while(!st.empty()){
                        char c = st.top();
                        st.pop();
                        ans += c;
                    }
                    ans += ' ';
                }
            }
        }
        if(!st.empty()){
            while(!st.empty()){
                char c = st.top();
                st.pop();
                ans += c;
            }
            ans += ' ';
        }
        
        return ans.substr(0,ans.size()-1);
    }
};