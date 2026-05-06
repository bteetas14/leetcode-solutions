class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int start = 0;
        int end = n-1;
        int maxi = -1e9;

        while(start<=end){
            int area = (end-start) * min(height[start], height[end]);
            maxi = max(maxi, area);

            if(height[start] < height[end]) start++;
            else end--;
        }
        return maxi;
    }
};