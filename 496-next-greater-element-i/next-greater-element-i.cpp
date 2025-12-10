class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> nge(nums2.size());
        stack<int> st;
        map<int, int> mpp;

        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(i<nums2.size()){
                if(!st.empty()){
                    nge[i] = st.top();
                    mpp[nums2[i]] = st.top();
                }
                else{
                    nge[i] = -1;
                    mpp[nums2[i]] = -1;
                }
            }
            st.push(nums2[i]);
        }
        
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};