class Solution {
public:
    int bfs(vector<int> adj[], int indi, vector<int>& visited) {
        queue<pair<int, int>> q;
        int cnt = 0;
        q.push({indi, -1});
        visited[indi] = 1; 
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node]) {
                if (visited[it] == 0) {
                    q.push({it, node});
                    visited[it] = 1;
                } else if (visited[it] == 1 && it != parent) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> visited(n, 0);
        vector<int> adj[n];

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0; // Count of redundant connections
        int cnt2 = 0; // Count of connected components
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                cnt2++;
                int k = bfs(adj, i, visited);
                cnt += k;
                cout << i << " " << k << endl;
            }
        }

        cnt /= 2; 

        if (cnt >= cnt2 - 1) {
            return cnt2 - 1;
        }
        return -1;
    }
};
g