class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {

        vector<vector<string>> trans;
        vector<string> ans;
        int n = transactions.size();
        vector<bool> invalid(n, false);

        for(auto it: transactions){
            vector<string> tokens;
            stringstream ss(it);
            string token;

            while(getline(ss, token, ',')){
                if(!token.empty()){
                    tokens.push_back(token);
                }
            }
            tokens.push_back(it);
            trans.push_back(tokens);
        }

        for(int i = 0; i < n; i++){
            int time_i = stoi(trans[i][1]);
            int amt_i = stoi(trans[i][2]);

            // Rule 1
            if(amt_i > 1000){
                invalid[i] = true;
            }

            // Rule 2
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                int time_j = stoi(trans[j][1]);

                if(trans[i][0] == trans[j][0] &&
                   abs(time_i - time_j) <= 60 &&
                   trans[i][3] != trans[j][3]){
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(invalid[i]){
                ans.push_back(trans[i][4]);
            }
        }

        return ans;
    }
};