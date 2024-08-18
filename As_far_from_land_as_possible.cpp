class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        int answer=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1)
               {
                q.push({i,j});
                visited[i][j]=1;
               }
            }
        }
        if(q.empty())
        return -1;
        int level=0;
    
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newx=x+dx[k];
                    int newy=y+dy[k];
                    if(newx>=0 && newx<n && newy>=0 && newy<n && visited[newx][newy]==0){
                        visited[newx][newy]=1;
                        answer=max(answer,level+1);
                        q.push({newx,newy});
                    }

                }

            }
            level++;
        }
        return answer;
        
    }
};