class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();
        int maxLen = 0, i, start = 0;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>> minh;

        priority_queue<pair<int, int>> maxh;

        for(int i=0; i<n && start<n; i++){
            maxh.push({nums[i], i});
            minh.push({nums[i], i});

            auto mini = minh.top();
            auto maxi = maxh.top();

            if(abs(maxi.first - mini.first) <= limit){
                maxLen = max(maxLen, i-start+1);
            }
            else{
                // int miniIdx = mini.second;
                while(abs(minh.top().first - maxh.top().first) > limit){
                    start++;
                    while(minh.top().second < start){
                        minh.pop();
                    }
                    while(maxh.top().second < start){
                        maxh.pop();
                    }
                }
            }
        }
        return maxLen;
    }
};