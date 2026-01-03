class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char, int> mpp;

        for(auto c:s){
            mpp[c]++;
        }

        for(auto c:t){
            if(mpp.find(c) == mpp.end()) return false;
            else{
                mpp[c]--;
            }
        }

        for(auto it:mpp){
            if(mpp[it.first] != 0) return false;
        }
        return true;
    }
};