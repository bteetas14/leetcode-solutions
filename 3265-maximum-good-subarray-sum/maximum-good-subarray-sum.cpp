
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        // value -> minimum prefix sum before that value
        unordered_map<int, long long> mpp;

        long long sum = 0;
        long long maxSum = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {

            // Store prefix sum BEFORE including nums[i]
            if (mpp.count(nums[i]) == 0) {
                mpp[nums[i]] = sum;
            } else {
                mpp[nums[i]] = min(mpp[nums[i]], sum);
            }

            // Include current element
            sum += nums[i];

            // Case 1: starting element = nums[i] - k
            if (mpp.count(nums[i] - k)) {
                maxSum = max(maxSum, sum - mpp[nums[i] - k]);
            }

            // Case 2: starting element = nums[i] + k
            if (mpp.count(nums[i] + k)) {
                maxSum = max(maxSum, sum - mpp[nums[i] + k]);
            }
        }

        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};
