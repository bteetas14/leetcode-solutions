class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int last = m + n - 1;
        int c1 = m-1, c2 = n-1;

        while(c1 >= 0 && c2 >= 0){
            if(nums1[c1] > nums2[c2]){
                nums1[last] = nums1[c1];
                last--;
                c1--;
            }
            else if(nums2[c2] > nums1[c1]){
                nums1[last] = nums2[c2];
                last--;
                c2--;
            }
            else if(nums1[c1] == nums2[c2]){
                nums1[last] = nums1[c1];
                c1--, last--;
                nums1[last] = nums2[c2];
                c2--, last--;
            }
        }

        while(c2 >= 0){
            nums1[last] = nums2[c2];
            c2--, last--;
        }
    }
};