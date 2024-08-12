class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>nge(m,-1);
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>nums2[st.top()])
            {
               st.pop();
            }
            if(!st.empty())
            nge[i]=st.top();
            st.push(i);

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]>=0?nums2[nge[j]]:-1);
                    break;
                }
            }
        }
        return ans;
    }
};