class Solution {
public:
    int totalSum;
    vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
        int totLengthOfSubarray = r - l + 1;
        vector<vector<int>> res(totLengthOfSubarray + 1);
        for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
            int sum = 0, countOfChosenNos = 0;
            for (int j = 0; j < totLengthOfSubarray; j++) {
                if (i & (1 << j)) {
                    sum += nums[l + j];
                    countOfChosenNos++;
                }
            }
            res[countOfChosenNos].push_back(sum);
        }
        return res;
    }

    int minimumDifference(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();

        auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
        auto right = findAllSubsetsSum(nums, n / 2, n - 1);
        int target = totalSum / 2, ans = INT_MAX;

        //we can take (0 to n/2) length numbers from left
        for (int i = 0; i <= n / 2; i++) {
            //now we take rest - (n/2-i) length from right, we sort it to binary search
            auto r = right[n / 2 - i];
            sort(begin(r), end(r));

            for (int curleftSum : left[i]) {
                int needSumFromRight = target - curleftSum;
                auto it = lower_bound(begin(r), end(r), needSumFromRight);
                if (it != end(r))
                    ans = min(ans, abs(totalSum - 2 * (curleftSum + *it)));
            }
        }
        return ans;
    }


    // int minimumDifference(vector<int>& arr) {

    //     int totSum = 0;
    //     int n = arr.size();

    //     // Calculate the total sum of the array
    //     for (int i = 0; i < n; i++) {
    //         totSum += arr[i];
    //     }

    //     // Initialize a DP table to store the results of the subset sum problem
    //     vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    //     // Base case: If no elements are selected (sum is 0), it's a valid subset
    //     for (int i = 0; i < n; i++) {
    //         dp[i][0] = true;
    //     }

    //     // Initialize the first row based on the first element of the array
    //     if (arr[0] <= totSum)
    //         dp[0][totSum] = true;

    //     // Fill in the DP table using a bottom-up approach
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int target = 1; target <= totSum; target++) {
    //             // Exclude the current element
    //             bool notTaken = dp[ind - 1][target];

    //             // Include the current element if it doesn't exceed the target
    //             bool taken = false;
    //             if (arr[ind] <= target)
    //                 taken = dp[ind - 1][target - arr[ind]];

    //             dp[ind][target] = notTaken || taken;
    //         }
    //     }

    //     int mini = 1e9;
    //     for (int i = 0; i <= totSum; i++) {
    //         if (dp[n - 1][i] == true) {
    //             // Calculate the absolute difference between two subset sums
    //             int diff = abs(i - (totSum - i));
    //             mini = min(mini, diff);
    //         }
    //     }
    //     return mini;
    // }
};