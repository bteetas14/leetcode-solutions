class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0, high = n-1, mid, ans=-1;

        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid]==target){
                ans = mid;
                high = mid-1;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(ans==-1) return false;
        int half = n/2;
        if(ans+half<n && nums[ans]==nums[ans+half]) return true;
        return false;
    }
};