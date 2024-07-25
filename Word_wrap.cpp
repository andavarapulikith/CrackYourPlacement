class Solution {
public:
    int rec(vector<vector<int>>& dp, int indi, int rem, vector<int>& nums, int k) {
        
        if (indi == nums.size()) {
            return 0;
        }

        if (dp[indi][rem] != -1) {
            return dp[indi][rem];
        }

        int ans = INT_MAX;
        int currentLength = 0;
        for (int j = indi; j < nums.size(); ++j) {
            currentLength += nums[j];
            if (currentLength > k) break;
            int remainingSpace = k - currentLength;
            int currentCost = (j == nums.size() - 1) ? 0 : (remainingSpace * remainingSpace);
            currentCost += rec(dp, j + 1, k, nums, k);
            ans = min(ans, currentCost);
            currentLength++;
        }

        dp[indi][rem] = ans;
        return ans;
    }

    int solveWordWrap(std::vector<int> nums, int k) {
        int n = nums.size();
      vector<vector<int>> dp(n, std::vector<int>(k + 1, -1));
        return rec(dp, 0, k, nums, k);
    }
};