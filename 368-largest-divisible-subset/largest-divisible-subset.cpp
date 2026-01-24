class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        int maxLen = 1;
        int ind = 0;

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                ind = i;
            }
        }

        vector<int> ans;
        while(ind != -1){
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};