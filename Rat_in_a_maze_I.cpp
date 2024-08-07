class Solution {
public:
    bool check(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    void dfs(vector<vector<int>>& mat, vector<vector<int>>& visited, int i, int j, vector<string>& ans, string curr) {
        int n = mat.size();
        if (i == n - 1 && j == n - 1) {
            ans.push_back(curr);
            return;
        }
        visited[i][j] = 1;
        int newi = i;
        int newj = j + 1;
        if (check(newi, newj, n) && mat[newi][newj] == 1 && visited[newi][newj] == 0) {
            dfs(mat, visited, newi, newj, ans, curr + 'R');
        }
        newi = i + 1;
        newj = j;
        if (check(newi, newj, n) && mat[newi][newj] == 1 && visited[newi][newj] == 0) {
            dfs(mat, visited, newi, newj, ans, curr + 'D');
        }
        newi = i - 1;
        newj = j;
        if (check(newi, newj, n) && mat[newi][newj] == 1 && visited[newi][newj] == 0) {
            dfs(mat, visited, newi, newj, ans, curr + 'U');
        }
        newi = i;
        newj = j - 1;
        if (check(newi, newj, n) && mat[newi][newj] == 1 && visited[newi][newj] == 0) {
            dfs(mat, visited, newi, newj, ans, curr + 'L');
        }

        visited[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int n = mat.size();
        if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return ans;
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        dfs(mat, visited, 0, 0, ans, "");
        return ans;
    }
};