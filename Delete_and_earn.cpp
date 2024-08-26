class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        // Find the maximum value in the nums array
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
        }
        vector<int> hash(maxi + 1, 0);
        for(int i = 0; i < n; i++){
            hash[nums[i]] += nums[i];
        }
        vector<int> dp(maxi + 1, 0);
        dp[0] = 0;          
        dp[1] = hash[1];   
        for(int i = 2; i <= maxi; i++){
            dp[i] = max(dp[i-1], hash[i] + dp[i-2]);
        }
        
        return dp[maxi];
    }
};
