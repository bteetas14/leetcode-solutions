//      [3 1 2 4]
// nse= [1 4 4 4]
// pse= [-1 -1 1 2]
// 
// i=0, left=0-(-1)=1, right=1-0=1, val=3*1*1=3, sum=3
// i=1, left=1-(-1)=2, right=4-1=3, val=1*2*3=6, sum=9
// i=2, left=2-1=1   , right=4-2=2, val=2*1*2=4, sum=13
// i=3, left=3-2=1   , right=4-3=1, val=4*1*1=4, sum=17
// 
class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            else{
                nse[i] = n;
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            else{
                pse[i] = -1;
            }
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {

        vector<int> pse = findPSEE(arr);
        vector<int> nse = findNSE(arr);
        int sum = 0, mod = 1e9 + 7;

        for(int i=0;i<arr.size();i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            long long freq = (left*right*1LL);

            int val = (arr[i]*freq*1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;    
    }
};