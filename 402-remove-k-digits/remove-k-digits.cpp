class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        vector<char> ans;
        if(n==k) return "0";
        string res = "";

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

        bool leading = true;
        for(char it:ans){
            if(leading && it=='0') continue;
            leading = false;
            res += it;
        }

        if(res=="") return "0";
        return res; 
    }
};