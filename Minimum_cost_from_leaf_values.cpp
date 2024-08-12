class Solution {
public:
    int solve(vector<int>& arr, map<pair<int,int>,int>& maxi, vector<vector<int>>& dp, int left, int right) {
        if (left == right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        
        int mini = INT_MAX;
        for (int i = left; i < right; i++) {
            mini = min(maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, dp, left, i) + solve(arr, maxi, dp, i+1, right), mini);
        }
        return dp[left][right] = mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, maxi, dp, 0, n-1);
    }
};
