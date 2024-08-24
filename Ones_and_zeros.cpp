class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> cnt;


        for (int i = 0; i < len; i++) {
            int zeros = 0, ones = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            }
            cnt.push_back({zeros, ones});
        }

      
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    int notTake = dp[i + 1][j][k]; 
                    int take = 0;

                    if (j >= cnt[i].first && k >= cnt[i].second) {
                        take = 1 + dp[i + 1][j - cnt[i].first][k - cnt[i].second];  
                    }

                    dp[i][j][k] = max(take, notTake); 
                }
            }
        }

        return dp[0][m][n];
    }
};
