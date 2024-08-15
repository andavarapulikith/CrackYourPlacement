class Solution {
public:
    int count(int n,vector<int>&dp){
        if(n<=1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=count(i-1,dp)*count(n-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return count(n,dp);
    }
};