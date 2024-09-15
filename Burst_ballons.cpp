class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<int>&nums){
        if(i>j)
        return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int indi=i;indi<=j;indi++){
            int cost=nums[i-1]*nums[indi]*nums[j+1]+f(i,indi-1,dp,nums)+f(indi+1,j,dp,nums);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp,nums);
        
    }
};