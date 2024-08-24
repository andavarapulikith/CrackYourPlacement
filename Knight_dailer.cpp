class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int>(n + 1, 0));
        int mod = 1e9 + 7;
        
        
        for (int i = 0; i < 10; i++) {
            dp[i][1] = 1;
        }
        
     
        vector<vector<int>> moves = {
            {4, 6},   
            {6, 8},   
            {7, 9},   
            {4, 8},   
            {0, 3, 9},
            {},       
            {0, 1, 7},
            {2, 6},  
            {1, 3},   
            {2, 4}   
        };
        for (int step = 2; step <= n; step++) {
            for (int i = 0; i < 10; i++) {
                for (int move : moves[i]) {
                    dp[i][step] = (dp[i][step] + dp[move][step - 1]) % mod;
                }
            }
        }
        
    
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[i][n]) % mod;
        }
        
        return ans;
    }
};
