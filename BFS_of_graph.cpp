class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        vector<int>ans;
        queue<int>q;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int k=q.front();
            ans.push_back(k);
            q.pop();
            for(int i=0;i<adj[k].size();i++){
                if(visited[adj[k][i]]==0)
                {
                    q.push(adj[k][i]);
                    visited[adj[k][i]]=1;
                }
            }
        }
        return ans;
    }
};