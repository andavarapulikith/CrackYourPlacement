class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='/')
            continue;
            string temp="";
            while(i<n && path[i]!='/')
            temp+=path[i++];
            if(temp=="..")
            {
            if(!st.empty())
            st.pop();
            }
            else if(temp=="."|| temp=="")
            continue;
            else
            st.push(temp);
            
        }
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();

        }
        return ans.length()>0?ans:"/";
        
    }
};