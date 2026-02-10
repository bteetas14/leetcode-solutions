class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
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
            while(!st.empty() && arr[st.top()]>arr[i]){
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