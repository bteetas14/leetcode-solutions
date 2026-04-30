/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &b) {

        auto d = b.dimensions();
        int n = d[0], m = d[1];
        int leftMostCol = m;
        
        for(int i=0;i<n;i++){
            int low = 0, high = m-1, mid, ans = -1;
            while(low<=high){
                mid = (low+high)/2;

                if(b.get(i, mid)==1){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(ans != -1){
                leftMostCol = min(leftMostCol, ans);
            }
        }
        if(leftMostCol==m) return -1;
        return leftMostCol;
    }
};