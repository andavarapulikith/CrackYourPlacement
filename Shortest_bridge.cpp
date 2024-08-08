class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
        int n = grid.size();
        visited[i][j] = 1;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if (newi >= 0 && newj >= 0 && newi < n && newj < n && visited[newi][newj] == 0 && grid[newi][newj] == 1) {
                dfs(grid, newi, newj, visited);
            }
        }
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int k = q.front().first;
                int l = q.front().second;
                q.pop();
                for (int a = 0; a < 4; a++) {
                    int newi = k + dx[a];
                    int newj = l + dy[a];
                    if (newi >= 0 && newi < n && newj >= 0 && newj < n) {
                        if (grid[newi][newj] == 0 && visited[newi][newj] == 0) {
                            q.push({newi, newj});
                            visited[newi][newj] = 1;
                        } else if (grid[newi][newj] == 1 && visited[newi][newj]==0) {
                            return cnt;
                        }
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    // Debug print to check visited array after DFS
                    for (const auto& row : visited) {
                        for (int val : row) {
                            cout << val << " ";
                        }
                        cout << endl;
                    }
                    return bfs(grid, visited);
                }
            }
        }
        return 0;
    }
};