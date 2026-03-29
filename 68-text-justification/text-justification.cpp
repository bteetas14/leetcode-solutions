class Solution {
public:
    string justifyToMaxWidth(string s, int len, int numWords, int maxWidth){
        int totalChars = 0;
        vector<string> words;
        string temp = "";

        // split words from s
        for(char c : s){
            if(c == ' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
                totalChars++;
            }
        }
        if(!temp.empty()) words.push_back(temp);

        int gaps = words.size() - 1;
        string justified = "";

        // single word case
        if(gaps == 0){
            justified = words[0];
            while(justified.size() < maxWidth) justified += ' ';
            return justified;
        }

        int spaces = maxWidth - totalChars;
        int even = spaces / gaps;
        int extra = spaces % gaps;

        for(int i = 0; i < words.size(); i++){
            justified += words[i];
            if(i < gaps){
                int spaceCount = even + (extra-- > 0 ? 1 : 0);
                justified += string(spaceCount, ' ');
            }
        }

        return justified;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int sumLen = 0, lineStart = 0;
        string s = "";

        for(int i=0;i<words.size();i++){
            if(sumLen + words[i].size() + lineStart <= maxWidth){
                if(lineStart == 0){
                    s += words[i];
                    sumLen += words[i].size();
                }
                else{
                    s += ' ' + words[i];
                    sumLen += words[i].size();
                }
                lineStart++;
            }
            else{
                string js = justifyToMaxWidth(s, sumLen, lineStart, maxWidth);
                ans.push_back(js);

                // reset
                s = "";
                sumLen = 0;
                lineStart = 0;

                i--; 
            }
        }

        string last = "";
        for(int i = 0; i < lineStart; i++){
            if(i > 0) last += ' ';
            last += words[words.size() - lineStart + i];
        }
        while(last.size() < maxWidth) last += ' ';

        ans.push_back(last);

        return ans;
    }
};