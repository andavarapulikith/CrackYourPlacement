class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else if(st.top().first==s[i])
            {
                int l=st.top().second+1;
                st.pop();
                if(l%k==0)
                continue;
                else
                st.push({s[i],l%k});
            }
            else{
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++)
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};