class Solution {
public:
    void reverseWords(vector<char>& s) {

        if(s.size()==1) return;

        reverse(s.begin(), s.end());

        int l = 0, r = 0;

        while(l < s.size()){
            while(r < s.size() && s[r] != ' '){
                r++;
            }
            int t = r-1;
            while(l <= t){
                swap(s[l], s[t]);
                t--;
                l++;
            }
            r++;
            l = r;
        }
        return;
    }
};