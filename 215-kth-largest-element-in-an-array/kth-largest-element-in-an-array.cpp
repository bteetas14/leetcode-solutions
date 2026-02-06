class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minH;
        int ans;
        
        for(auto i:nums){
            minH.push(i);
            if(minH.size()>k){
                minH.pop();
            }
        }
        return minH.top();
    }
};