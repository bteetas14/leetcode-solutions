class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        priority_queue<pair<int, int>> maxh;
        int start = 0, maxLen = -1e9;

        for(int i=0;i<n;i++){
            minh.push({nums[i], i});
            maxh.push({nums[i], i});

            if(abs(minh.top().first - maxh.top().first) <= limit){
                maxLen = max(maxLen, i-start+1); 
            }
            else{
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