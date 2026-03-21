class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) != mpp.end()){
            auto &ds = mpp[key];
            int low = 0, high = ds.size()-1, mid;
            string ans = "";

            while(low<=high){
                mid = (low+high)/2;
                if(ds[mid].first == timestamp){
                    return ds[mid].second;
                }
                if(ds[mid].first > timestamp){
                    high = mid-1;
                }
                else{
                    ans = ds[mid].second;;
                    low = mid+1;
                }
            }
            return ans;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */