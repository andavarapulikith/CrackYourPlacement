class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkdfs(vector<int>adj[],int indi,vector<int>&visited,vector<int>&pathvisited){
        visited[indi]=1;
        pathvisited[indi]=1;
        for(auto it:adj[indi]){
            if(visited[it]==0){
                if(checkdfs(adj,it,visited,pathvisited)==true)
                return true;
            }
            else if(pathvisited[it]==1)
            return true;
        }
        pathvisited[indi]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        for(int i=0;i<V;i++){
            if(checkdfs(adj,i,visited,pathvisited))
            return true;
        }
        return false;
        
    }
};
