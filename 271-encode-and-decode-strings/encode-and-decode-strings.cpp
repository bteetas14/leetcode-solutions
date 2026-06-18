class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        int n = strs.size();
        string res = "";

        for(auto it:strs){
            res += to_string(it.size()) + "#" + it;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract string
            string word = s.substr(j + 1, len);
            res.push_back(word);

            // Move to next encoded string
            i = j + 1 + len;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));