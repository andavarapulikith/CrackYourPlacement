class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int indi,vector<int>adj[],vector<int>&visited,vector<int>&ans){
        visited[indi]=1;
        ans.push_back(indi);
        for(auto it:adj[indi]){
            if(visited[it]==0)
            dfs(it,adj,visited,ans);
        }
        
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>visited(V,0);
        dfs(0,adj,visited,ans);
        return ans;
    }
};