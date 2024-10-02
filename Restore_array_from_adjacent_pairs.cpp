class Solution {
public:
    void dfs(map<int,vector<int>>&mpp,int node,set<int>&visited,vector<int>&ans){
        if(visited.find(node)!=visited.end())
        return;
        visited.insert(node);
        ans.push_back(node);
        for(auto it:mpp[node]){
            dfs(mpp,it,visited,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>>mpp;
        int n=adjacentPairs.size();
        for(auto it:adjacentPairs){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }
        int start=-1;
        n=mpp.size();
        for(auto it:mpp){
            if(it.second.size()==1)
            {
                start=it.first;
                break;
            }
        }
        set<int>visited;
        vector<int>ans;
        dfs(mpp,start,visited,ans);
        return ans;
        
    }
};