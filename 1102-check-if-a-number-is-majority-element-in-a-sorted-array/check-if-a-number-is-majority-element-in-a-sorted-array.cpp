class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (first == -1) return false;

        return first + n/2 < n && nums[first + n/2] == target;
    }
};