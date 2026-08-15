class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int start = 0, end = n-1;
        int area;
        int maxi = INT_MIN;

        while(start<end){
            area = (end-start) * min(height[start], height[end]);
            maxi = max(area, maxi);
            
            if(height[start]<height[end]) start++;
            else end--;
        }
        return maxi;
    }
};