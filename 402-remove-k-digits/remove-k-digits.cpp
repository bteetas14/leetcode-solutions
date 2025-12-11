class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        if(n==k) return "0";
        vector<char> ans;

        for(int i=0;i<n;i++){
            while(!ans.empty() && ans.back()>num[i] && k>0){
                ans.pop_back();
                k--;
            }

            ans.push_back(num[i]);
        }

        while(!ans.empty() && k>0){
            ans.pop_back();
            k--;
        }

        // if(ans.empty()) return "0";

        string res="";
        bool leading = true;
        
        for(auto it:ans){
            if(leading && it=='0') continue;
            leading = false;
            res += it;
        }

        if(res == "") return "0";

        return res;
        
    }
};