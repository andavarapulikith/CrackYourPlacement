class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        int len=strs[0].length();
        int flag=0;
        int there=1;
        for(int i=0;i<len;i++){
            char ch=strs[0][i];
            int count=1;
            for(int j=1;j<n;j++){
                 if(i>=strs[j].length())
                 {
                    flag=1;
                    break;
                 }
                 if(strs[j][i]==ch)
                 count++;
            }
            if(count==n)
            ans+=ch;
            if(count!=n)
            break;
            if(flag==1)
            break;
            
        }
        return ans;
        
    }
};