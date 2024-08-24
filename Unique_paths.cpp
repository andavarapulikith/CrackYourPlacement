class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=0;i<m;i++)
        dp[i][n-1]=1;
        for(int i=0;i<n;i++)
        dp[m-1][i]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int left=0;
                int top=0;
                if(i+1<m)
                left=dp[i+1][j];
                if(j+1<n)
                top=dp[i][j+1];
                dp[i][j]=left+top;


            }
        }
        return dp[0][0];


        
    }
};