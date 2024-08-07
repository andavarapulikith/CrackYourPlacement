class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       queue<pair<int,int>>q;
       int n=image.size();
       int m=image[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       int dx[]={0,1,0,-1};
       int dy[]={1,0,-1,0};
       int stcolor=image[sr][sc];
       image[sr][sc]=color;
       q.push({sr,sc});
       visited[sr][sc]=1;
       while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dx[k];
            if(newi>=0 && newj>=0 && newi<n && newj<m && visited[newi][newj]==0 && image[newi][newj]==stcolor){
                q.push({newi,newj});
                image[newi][newj]=color;
                visited[newi][newj]=1;
            }
        }

       }
       return image;
        
    }
};