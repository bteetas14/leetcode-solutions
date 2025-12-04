class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int prev = 0;
        int count = 0;

        for (int i = 1; i < n; i++) {

            if (intervals[prev][1] <= intervals[i][0]) {
                prev = i; 
            } else {
                count++;
                if (intervals[i][1] < intervals[prev][1]) {
                    prev = i;   // keep the smaller end interval
                }
            }
        }
        return count;
    }
};
