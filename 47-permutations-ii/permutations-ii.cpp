#include <bits/stdc++.h>
class Solution {
public:
    void solve(int ind, vector<int>& nums, set<vector<int>>& st){
        if(ind==nums.size()){
            st.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,st);
            swap(nums[ind],nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
        set<vector<int>> st;

        solve(0,nums,st);

        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};