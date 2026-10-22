
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        int ans = 0;

        for (int x : deliciousness) {

            // Check every possible power of 2
            for (int i = 0; i <= 21; i++) {
                int target = 1 << i;
                int complement = target - x;

                // Count previously seen complements
                if (freq.count(complement)) {
                    ans = (ans + freq[complement]) % MOD;
                }
            }

            // Insert only after checking
            freq[x]++;
        }

        return ans;
    }
};
