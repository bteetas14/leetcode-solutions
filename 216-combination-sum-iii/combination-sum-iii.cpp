class Solution {
public:
    void findCombination3(int num, int k, int target, vector<int>& ds, vector<vector<int>>& ans){

        if(ds.size()==k && target==0){
            ans.push_back(ds);
            return;
        }

        if(ds.size()>=k || num>=10){
            return;
        }

        for(int i=num;i<10;i++){
            if(i<=target){
                ds.push_back(i);
                findCombination3(i+1, k, target-i, ds, ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) {

        vector<int> ds;
        vector<vector<int>> ans;

        findCombination3(1, k, target, ds, ans);
        return ans;
    }
};