class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char,int> need, have;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            have[c]++;

            if (need.count(c) && have[c] == need[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char lc = s[left];
                have[lc]--;
                if (need.count(lc) && have[lc] < need[lc])
                    formed--;

                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {

//         if (t.size() > s.size()) return "";

//         map<char, int> tmap;
//         for(int i=0;i<t.size();i++){
//             tmap[t[i]]++;
//         }

//         map<char, int> smap;
//         int minlen = INT_MAX, start, end, left = 0;
//         string ans = "";

//         for(int i=0;i<s.size();i++){
//             smap[s[i]]++;

//             for(auto it:tmap){
//                 while(smap[it.first] > it.second){
//                     smap[s[left]]--;
//                     left++;
//                 }
//             }

//             if((i-left+1) < minlen){
//                 minlen = (i-left+1);
//                 start = left;
//                 end = i;
//             }
//         }

//         for(int i=start;i<=end;i++){
//             ans += s[i];
//         }
//         return ans;
//     }
// };
