class Solution {
public:
    int longest_path(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j){
        int maxi=1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        int n=matrix.size();
        int m=matrix[0].size();
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            if(newi>=0 && newi<n && newj>=0 && newj<m && matrix[newi][newj]>matrix[i][j])
            maxi=max(maxi,1+longest_path(matrix,dp,newi,newj));
        }
        return dp[i][j]=maxi;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   maxi=max(maxi,longest_path(matrix,dp,i,j));
            }
        }
        return maxi;
    }
};