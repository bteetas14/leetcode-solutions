class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        int candies = n, i = 1;

        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;

            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                candies += peak;
                i++;
            }

            int valley = 0;

            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candies += valley;
                i++;
            }
            candies -= min(peak, valley);
        }
        return candies;
    }
};