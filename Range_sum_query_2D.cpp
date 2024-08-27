class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
       int  r=matrix.size();
        int c=matrix[0].size();
        dp.resize(r+1,vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = dp[row2+1][col2+1] -dp[row1][col2+1] - dp[row2+1][col1] +dp[row1][col1];
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */