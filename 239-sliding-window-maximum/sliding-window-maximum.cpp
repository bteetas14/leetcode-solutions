class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;

        // Stores indices
        deque<int> dq;

        for(int i = 0; i < n; i++) {

            // 1. Remove indices which are outside current window
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from back
            // They can never become maximum
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(i);

            // 4. Start adding answers once first window is complete
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};