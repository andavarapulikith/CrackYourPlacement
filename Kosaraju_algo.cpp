class Solution
{
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, stack<int>& st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == 0)
                dfs(adj, visited, it, st);
        }
        st.push(node);
    }

    void dfs2(vector<vector<int>>& adjT, vector<int>& visited, int node) {
        visited[node] = 1;
        for (auto it : adjT[node]) {
            if (visited[it] == 0)
                dfs2(adjT, visited, it);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        // code here
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0)
                dfs(adj, visited, i, st);
        }
        
   
        vector<vector<int>> adjT(V);
        
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (auto it : adj[i])
                adjT[it].push_back(i);
        }
        
        int cnt = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop(); 
            if (visited[node] == 0) {
                cnt++;
                dfs2(adjT, visited, node);
            }
        }
        return cnt;
    }
};