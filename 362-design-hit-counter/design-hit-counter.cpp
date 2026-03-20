class HitCounter {
public:
    priority_queue<int, vector<int>, greater<int>> minh;
    
    HitCounter() {}
    
    void hit(int timestamp) {
        minh.push(timestamp);
    }
    
    int getHits(int timestamp) {
        if(timestamp<=300) return minh.size();

        int limit = timestamp-300;
        while(!minh.empty() && minh.top()<=limit){
            minh.pop();
        }
        return minh.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */