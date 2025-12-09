class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // leftSums[k] → sums using k elements
        vector<vector<int>> leftSums(n + 1), rightSums(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += left[i];
                }
            }
            leftSums[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += right[i];
                }
            }
            rightSums[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(rightSums[i].begin(), rightSums[i].end());

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : leftSums[k]) {
                int need = total / 2 - s1;
                auto &v = rightSums[n - k];

                auto it = lower_bound(v.begin(), v.end(), need);
                if (it != v.end())
                    ans = min(ans, abs(total - 2 * (s1 + *it)));
                if (it != v.begin())
                    ans = min(ans, abs(total - 2 * (s1 + *prev(it))));
            }
        }

        return ans;
    }
};
