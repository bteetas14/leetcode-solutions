class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> mpp;

        if(s.size() != t.size()) return false;

        for(auto c:s){
            mpp[c]++;
        }

        for(auto c:t){
            if(mpp.find(c)==mpp.end()) return false;
            else{
                mpp[c]--;
            }
        }

        for(auto it:mpp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
