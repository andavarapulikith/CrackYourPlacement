class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int, int>> q; 
        q.push({headID, 0});
        int totalTime = 0;

        while (!q.empty()) {
            int employee = q.front().first;
            int time = q.front().second;
            q.pop();

            totalTime = max(totalTime, time);

            for (int subordinate : adj[employee]) {
                q.push({subordinate, time + informTime[employee]});
            }
        }

        return totalTime;
    }
};
