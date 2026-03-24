class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> minh;
        
        priority_queue<pair<int, int>> maxh;
        int mini = 1e9, maxi = -1e9, start = 0, maxLen = -1e9;

        for(int i=0;i<n;i++){
            minh.push({nums[i], i});
            maxh.push({nums[i], i});

            mini = min(mini, minh.top().first);
            maxi = max(maxi, maxh.top().first);

            if(abs(maxh.top().first - minh.top().first) <= limit){
                maxLen = max(maxLen, i-start+1);
            }
            else{
                while(abs(maxh.top().first - minh.top().first) > limit){
                    start++;
                    while(maxh.top().second < start){
                        maxh.pop();
                    }
                    while(minh.top().second < start){
                        minh.pop();
                    }
                }
            }
        }
        return maxLen;
    }
};