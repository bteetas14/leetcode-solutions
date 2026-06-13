class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> preProduct(n);
        vector<int> suffProduct(n);
        preProduct[0] = 1;
        suffProduct[n-1] = 1;

        for(int i=1;i<n;i++){
            preProduct[i] = preProduct[i-1] * nums[i-1];
            suffProduct[n-1-i] = suffProduct[n-1-i+1] * nums[n-1-i+1];
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = preProduct[i] * suffProduct[i];
        }
        return ans;
    }
};