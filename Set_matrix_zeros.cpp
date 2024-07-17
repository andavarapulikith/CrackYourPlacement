class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>nrows(n,0);
        vector<int>ncols(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    nrows[i]=1;
                    ncols[j]=1;
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nrows[i]==1 || ncols[j]==1)
                matrix[i][j]=0;
            }
        }

        
    }
};