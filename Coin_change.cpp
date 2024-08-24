class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); 
        dp[0] = 0;  
        
        for (int i = 0; i <= amount; i++) {
            if (dp[i] == amount + 1) continue;  
            
            for (auto it : coins) {
                if(it>amount)
                continue;
                if (i + it <= amount ) {
                    dp[i + it] = min(dp[i + it], dp[i] + 1);
                }
            }
        }
        
        return dp[amount] == amount + 1 ? -1 : dp[amount];  
    }
};
