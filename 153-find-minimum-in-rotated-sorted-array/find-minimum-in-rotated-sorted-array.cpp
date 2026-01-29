class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int low = 0, high = n-1;
        int mid, mini = 1e9;

        while(low<=high){
            mid = (low+high)/2;

            mini = min(mini, nums[mid]);

            if(nums[mid]>nums[high] && nums[low]<=nums[mid]){
                low = mid+1;
            }
            else if(nums[mid]<=nums[high] && nums[low]>nums[mid]){
                high = mid-1;
            }
            else{
                high = mid-1;
            }
        }
        return mini;
    }
};