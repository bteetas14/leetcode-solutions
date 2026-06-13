class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();
        int m = t.size();

        if(n!=m) return false;
        map<char, int> mpp;

        for(auto it:s){
            mpp[it]++;
        }

        for(auto it:t){
            mpp[it]--;
            if(mpp[it]==0){
                mpp.erase(it);
            }
        }
        if(mpp.size()>0) return false;
        return true;
    }
};