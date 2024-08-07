class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool bfs(vector<int>adj[],int indi,vector<int>&visited){
       queue<pair<int,int>>q;
       visited[indi]=1;
       q.push({indi,-1});
       while(!q.empty()){
           int k=q.front().first;
           int parent=q.front().second;
           q.pop();
           for(auto it:adj[k]){
               if(visited[it]==0)
               {
               q.push({it,k});
               visited[it]=1;
               }
               else if(it!=parent)
               return true;
           }
       }
       return false;
   }
   
   bool dfs(int indi,int parent,vector<int>adj[],vector<int>&visited){
       visited[indi]=1;
       for(auto it:adj[indi]){
           if(visited[it]==0)
           {
           if(dfs(it,indi,adj,visited)==true)
           return true;
           }
           else if(parent!=it)
           return true;
       }
       return false;
       
   }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0)
            {
            bool val=dfs(i,-1,adj,visited);
            if(val)
            return true;
            }
            
            
        }
        return false;
    }
};