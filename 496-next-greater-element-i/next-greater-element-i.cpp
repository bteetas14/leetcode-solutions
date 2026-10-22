class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        int n = nums2.size();
        int n1 = nums1.size();
        vector<int> nge(n);
        vector<int> ans(n1);
        map<int, int> mpp;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }

            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(nums2[i]);
        }
        

        for(int i=0;i<n;i++){
            mpp[nums2[i]] = i;
        }

        for(int i=0;i<nums1.size();i++){
            if(mpp.count(nums1[i]) > 0){
                ans[i] = nge[mpp[nums1[i]]];
            }
        }
        return ans;
    }
};