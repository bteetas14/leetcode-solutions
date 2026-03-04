class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> freqMap;
        for(auto it:nums){
            freqMap[it]++;
        }

        vector<int> res;

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> minh;
        
        for(auto it:freqMap){
            int num = it.first;
            int freq = it.second;
            minh.push({freq, num});
            if(minh.size()>k){
                minh.pop();
            }
        }

        while(!minh.empty()){
            res.push_back(minh.top().second);
            minh.pop();
        }
        return res;
    }
};