class Solution {
public:
    void recur(int n,vector<int>&temp,int k,vector<vector<int>>&ans){
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(n==0)
        return;
        temp.push_back(n);
        recur(n-1,temp,k-1,ans);
        temp.pop_back();
        recur(n-1,temp,k,ans);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        recur(n,temp,k,ans);
        return ans;

        
    }
};