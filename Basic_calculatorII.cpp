class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int len=s.length();
        char oper='+';
        int num=0;
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            if((!isdigit(s[i])&& s[i]!=' ') || i==len-1){
                if(oper=='+')
                st.push(num);
                else if(oper=='-')
                st.push(-num);
                else if(oper=='*'){
                    int val=st.top()*num;
                    st.pop();
                    st.push(val);
                }
                else if(oper=='/'){
                    int val=st.top()/num;
                    st.pop();
                    st.push(val);
                }
                num=0;
                oper=s[i];


            }
            
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};