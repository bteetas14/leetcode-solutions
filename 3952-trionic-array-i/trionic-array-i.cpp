class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // Must have at least one increase
        if (i == 0 || i == n - 1) return false;

        // Phase 2: strictly decreasing
        int peak = i;

        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        // Must have at least one decrease
        if (i == peak || i == n - 1) return false;

        // Phase 3: strictly increasing
        int valley = i;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // Must have at least one increase
        if (i == valley) return false;

        // Entire array should be consumed
        return i == n - 1;
    }
};