class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        int len1=s.length();
        int len2=t.length();
        for(int i=0;i<len1;i++){
            if(s[i]=='#' && !st1.empty())
            st1.pop();
            else if(s[i]!='#')
            st1.push(s[i]);
        }
         for(int i=0;i<len2;i++){
            if(t[i]=='#' && !st2.empty())
            st2.pop();
            else if(t[i]!='#')
            st2.push(t[i]);
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()!=st2.top())
            return false;
            st1.pop();
            st2.pop();
        }
        return st1.empty() && st2.empty();

    }
};