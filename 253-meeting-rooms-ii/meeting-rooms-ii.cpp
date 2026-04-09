class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if(n==1) return 1;
        sort(intervals.begin(), intervals.end());

        priority_queue<int,
            vector<int>,
            greater<int>> pq;
        
        pq.push(intervals[0][1]);

        for(int i=1;i<intervals.size();i++){
            if(!pq.empty() && intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};