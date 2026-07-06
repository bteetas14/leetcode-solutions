class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // even index -- positive num
        // odd index -- negative num

        int n = nums.size();

        vector<int> newArr(n);

        int pos = 0, neg = 1;

        for(int i=0;i<n;i++){
            if(nums[i]>0){  //postive
                newArr[pos] = nums[i];
                if(pos+2<n) pos += 2;
            }
            else{ //negative
                newArr[neg] = nums[i];
                if(neg+2<n) neg += 2;
            }
        }
        return newArr;
    }
};