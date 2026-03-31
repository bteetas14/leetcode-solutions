class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if(n==0) return 0;
        map<char, int> mpp;

        int maxLen = INT_MIN, start = 0;

        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]] = i;
            }
            else{
                // start = mpp[s[i]] + 1;
                if(mpp[s[i]]+1 > start) start = mpp[s[i]] + 1;
                mpp[s[i]] = i;
            }
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};