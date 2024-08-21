class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp;
        dp.push_back(1);
        int p1=0;
        int p2=0;
        int p3=0;
        for(int i=1;i<n;i++){
              int twom=dp[p1]*2;
              int threem=dp[p2]*3;
              int fivem=dp[p3]*5;
              int k=min(twom,min(threem,fivem));
              dp.push_back(k);
              if(twom==k)
              p1++;
              if(threem==k)
              p2++;
              if(fivem==k)
              p3++;


        }
        return dp[n-1];
        
    }
};