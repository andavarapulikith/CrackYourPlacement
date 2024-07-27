class Solution {
public:
    int rec(vector<vector<int>>&dp,string s,string t,int i,int j){
        if(j==t.length())
        return 1;
        if(i==s.length())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=rec(dp,s,t,i+1,j+1)+rec(dp,s,t,i+1,j);
        }
        return dp[i][j]=rec(dp,s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        return rec(dp,s,t,0,0);
        
    }
};