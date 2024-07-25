
#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word = "";
      for (auto x : s)
    {
        if(x==' '&& word=="");
        
        else if (x==' ')
        {
           
            st.push(word);
             st.push(" ");
             
            word = "";
        }
        else {
            word = word + x;
        }
    }
   st.push(word);
  string ans="";
   while(!st.empty())
   {  
     ans=ans+st.top();
     st.pop();
       
   }
   int flag=0;
   string ans1="";
 if(ans[0]==' ')
 ans.erase(0,1);
 return ans;
    }
};