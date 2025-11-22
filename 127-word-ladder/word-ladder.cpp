class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string> wordSet(wordList.begin(), wordList.end());
        vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        queue<pair<string, int>> q;
        // word, len
        q.push({beginWord, 1});
        int finalSteps = 0;

        while(!q.empty()){
            auto [word, steps] = q.front();

            if(word==endWord){
                finalSteps = steps;
                break;
            }

            q.pop();

            for(int i=0;i<word.size();i++){
                for(int j=0;j<26;j++){

                    string tempWord = word;
                    tempWord[i] = alphabet[j];

                    if(wordSet.find(tempWord)!=wordSet.end()){
                        q.push({tempWord, steps+1});
                        wordSet.erase(tempWord);
                    }
                }
            }
        }
        return finalSteps;
    }
};
