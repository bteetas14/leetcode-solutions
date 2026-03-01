class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        int low = 0, high = n-1;

        while(low<=high){
            if(numbers[low]+numbers[high]==target){
                return {low+1, high+1};
            }
            else if(numbers[low]+numbers[high]>target){
                high--;
            }
            else{
                low++;
            }
        }
        return {-1, -1};
    }
};