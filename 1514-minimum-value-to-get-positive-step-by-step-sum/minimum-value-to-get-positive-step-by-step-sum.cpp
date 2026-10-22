class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int sum = 0, mini = 1e9;
        bool negative = false;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum < 0) negative = true;
            mini = min(mini, sum);
        }

        if(negative == false) return 1;

        if(mini>0) return mini;

        return abs(mini) + 1;
        
    }
};