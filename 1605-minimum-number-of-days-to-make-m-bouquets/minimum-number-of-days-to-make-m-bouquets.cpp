class Solution {
public:
    int numBouquets(int num, vector<int>&bloomDay, int m, int k){
        int b = 0;
        int cnt = 0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=num){
                cnt++;
                if(cnt%k==0) b++;
                // if((i+1)%k==0) b++;
            }
            else{
                cnt = 0;
            }
        }
        return b;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int maxDays = -1e9;
        int n = bloomDay.size();
        
        long long totalele = 1LL*m*k;
        if(totalele > n) return -1;

        for(int i=0;i<n;i++){
            maxDays = max(maxDays, bloomDay[i]);
        }

        int low = 1, high = maxDays, mid;

        while(low<=high){
            mid = (low+high)/2;

            int numBouq = numBouquets(mid, bloomDay, m, k);

            if(numBouq<m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};