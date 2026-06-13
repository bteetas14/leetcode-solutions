class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        int right = n-1, left = 0;

        while(left<=right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};