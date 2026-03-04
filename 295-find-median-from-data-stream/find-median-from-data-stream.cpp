class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minh.push(num);
        maxh.push(minh.top());
        minh.pop();

        if(maxh.size()>minh.size()){
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size() > maxh.size()){
            return minh.top()/1.0;
        }
        else{
            return (maxh.top() + minh.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */