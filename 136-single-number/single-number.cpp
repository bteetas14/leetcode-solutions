class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        int missing = 0;

        for(int i=0;i<n;i++){
            missing ^= nums[i];
        }
        return missing;
        
    }
};