class Solution{
public:
    void dfs(vector<vector<char>>&mat,vector<vector<int>>&visited,int i,int j){
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int new_i=i+dx[k];
            int new_j=j+dy[k];
            if(new_i>=0 && new_i<mat.size()&& new_j>=0 && new_j<mat[0].size()&& mat[new_i][new_j]=='O'&& visited[new_i][new_j]==0)
            dfs(mat,visited,new_i,new_j);
        }
            }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'&&visited[i][0]==0)
            dfs(mat,visited,i,0);
            if(mat[i][m-1]=='O'&& visited[i][m-1]==0)
            dfs(mat,visited,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'&& visited[0][i]==0)
            dfs(mat,visited,0,i);
            if(mat[n-1][i]=='O' && visited[n-1][i]==0)
            dfs(mat,visited,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && visited[i][j]==0)
                mat[i][j]='X';
            }
        }
        return mat;
    }
};