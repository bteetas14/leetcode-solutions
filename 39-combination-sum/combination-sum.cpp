class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(target<0) return;

        if(ind==candidates.size()){
            if(target==0) ans.push_back(ds);
            return;
        }

        ds.push_back(candidates[ind]);
        solve(ind, target-candidates[ind], candidates, ds, ans);
        ds.pop_back();

        solve(ind+1, target, candidates, ds, ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> ds;
        vector<vector<int>> ans;

        solve(0, target, candidates, ds, ans);

        return ans;
        
    }
};