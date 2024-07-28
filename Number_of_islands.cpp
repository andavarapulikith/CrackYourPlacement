class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            pair<int,int>k=q.front();
            q.pop();
            int x=k.first;
            int y=k.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0)
                    continue;
                    int new_x=x+i;
                    int new_y=y+j;
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&visited[new_x][new_y]!=1 && grid[new_x][new_y]=='1'){
                        visited[new_x][new_y]=1;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    cnt++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};