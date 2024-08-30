class Solution {
public:
    int minInsertions(string s) {
        string str1=s;
        reverse(s.begin(),s.end());
        int n=str1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==s[j-1])
                curr[j]=prev[j-1]+1;
                else
                curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return n-curr[n];
        
    }
};