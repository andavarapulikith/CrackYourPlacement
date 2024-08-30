class Solution {
public:
    bool f(vector<vector<int>>&dp,vector<int>&stones,int indi,int k){
        if(indi>=stones.size())
        return false;
        if(indi==stones.size()-1)
        return true;
        if(dp[indi][k]!=-1)
        return dp[indi][k];
        bool flag=false;
        for(int i=indi+1;i<stones.size();i++){
            int diff=stones[i]-stones[indi];
            if(diff>k+1)
            break;
            if(diff==k-1)
            flag=flag || f(dp,stones,i,k-1);
            if(diff==k)
            flag=flag|| f(dp,stones,i,k);
            if(diff==k+1)
            flag=flag || f(dp,stones,i,k+1);


        }
        return dp[indi][k]=flag;
    }
    bool canCross(vector<int>& stones) {
        if (stones.size() > 1 && stones[1] != 1) return false;
        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(dp,stones,1,1);

    }
};