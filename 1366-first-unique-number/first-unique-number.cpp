class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> freq;

    FirstUnique(vector<int>& nums) {
        for(auto it:nums){
            freq[it]++;
            q.push(it);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && freq[q.front()]>1){
            q.pop();
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    
    void add(int value) {
        q.push(value);
        freq[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */