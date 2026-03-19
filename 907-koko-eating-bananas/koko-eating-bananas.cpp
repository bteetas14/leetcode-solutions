class Solution {
public:
    long long findHours(int num, vector<int>& piles, int h){
        long long tothrs = 0;
        int n = piles.size();

        for(int i=0;i<n;i++){
            if(piles[i]<num){
                tothrs++;
                continue;
            }
            tothrs += (piles[i]/num);
            if(piles[i]%num > 0) tothrs++;
        }
        return tothrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = -1e9;
        int n = piles.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi, piles[i]);
        }

        int low = 1, high = maxi, mid;
        
        while(low<=high){
            mid = (low+high)/2;

            long long hrs = findHours(mid, piles, h);
            if(hrs<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};