class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        if(nums.size()==0) return {{lower, upper}};
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){

            if(i==0){
                if(nums[i]==lower) continue;
                else{
                    ans.push_back({lower, nums[i]-1});
                }
            }

            if(i>0){
                if(nums[i]==nums[i-1]+1) continue;
                else{
                    ans.push_back({nums[i-1]+1, nums[i]-1});
                }
            }
        }
        if(nums[nums.size()-1] != upper) ans.push_back({nums[nums.size()-1]+1, upper});
        return ans;
    }
};