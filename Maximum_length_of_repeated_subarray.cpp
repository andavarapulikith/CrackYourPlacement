class Solution {
public:
    int recur(vector<vector<int>>&dp,vector<int>&nums1,vector<int>&nums2,int i,int j,int &maxi ){
        if(i==nums1.size() || j==nums2.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        dp[i][j]=0;
        if(nums1[i]==nums2[j])
        {
        dp[i][j]=1+recur(dp,nums1,nums2,i+1,j+1,maxi);
        maxi=max(maxi,dp[i][j]);
        }
        
        recur(dp,nums1,nums2,i,j+1,maxi);
        recur(dp,nums1,nums2,i+1,j,maxi);
        
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi=0;
      recur(dp,nums1,nums2,0,0,maxi);
      return maxi;
        
        
    }
};