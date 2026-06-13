class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freqMap;
        for(auto it:nums){
            freqMap[it]++;
        }
        
        vector<int> res;
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> minh;
        
        for(auto it:freqMap){
            int freq = it.second;
            int num = it.first;

            minh.push({freq, num});
            while(minh.size() > k){
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