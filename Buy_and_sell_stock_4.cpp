class Solution {
public:
    int f(vector<vector<int>>&dp,int indi,int tranno,vector<int>&prices,int k){
        if(indi==prices.size() || tranno==2*k)
        return 0;
        if(dp[indi][tranno]!=-1)
        return dp[indi][tranno];
        if(tranno%2==0){
            return dp[indi][tranno]= max(f(dp,indi+1,tranno,prices,k),-prices[indi]+f(dp,indi+1,tranno+1,prices,k));
        }
        return dp[indi][tranno]=max(f(dp,indi+1,tranno,prices,k),prices[indi]+f(dp,indi+1,tranno+1,prices,k));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k+1,-1));
        return f(dp,0,0,prices,k);
        
    }
};