//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int min_value(vector<vector<int>>& cost, vector<vector<int>>& dp, int mask, int city) {
        int n = cost.size();
        if (mask == (1 << n) - 1) {
            return cost[city][0];  
        }
        if (dp[mask][city] != -1) {
            return dp[mask][city];
        }
        int mini = INT_MAX;
        for (int i = 0; i < cost.size(); i++) {
            if ((mask & (1 << i)) == 0) {  
                mini = min(mini, cost[city][i] + min_value(cost, dp, mask | (1 << i), i));
            }
        }
        return dp[mask][city] = mini; 
    }

    int total_cost(vector<vector<int>> cost) {
        int n = cost.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        return min_value(cost, dp, 1, 0);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends