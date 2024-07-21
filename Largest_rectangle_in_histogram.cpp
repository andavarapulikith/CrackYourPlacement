class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ls(n,0);
        vector<int>rs(n,n-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty())
            ls[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty())
            rs[i]=st.top()-1;
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        ans=max(ans,(rs[i]-ls[i]+1)*heights[i]);
        return ans;

        
        
    }
};