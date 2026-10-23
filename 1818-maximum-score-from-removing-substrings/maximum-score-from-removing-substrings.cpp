
class Solution {
public:
    pair<string, int> removePair(string s, char a, char b, int points) {
        string st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.back() == a && c == b) {
                st.pop_back();
                score += points;
            } else {
                st.push_back(c);
            }
        }

        return {st, score};
    }

    int maximumGain(string s, int x, int y) {
        int totSum = 0;

        if (x >= y) {
            auto [remaining, score1] = removePair(s, 'a', 'b', x);
            auto [finalString, score2] = removePair(remaining, 'b', 'a', y);
            totSum = score1 + score2;
        } else {
            auto [remaining, score1] = removePair(s, 'b', 'a', y);
            auto [finalString, score2] = removePair(remaining, 'a', 'b', x);
            totSum = score1 + score2;
        }

        return totSum;
    }
};
