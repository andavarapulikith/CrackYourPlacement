class Solution {
public:
    void recur(string str,int n,int open,int closed,vector<string>&ans){
        if(str.length()==n*2){
            ans.push_back(str);
            return;
        }
        if(open<n)
        recur(str+"(",n,open+1,closed,ans);
        if(closed<open)
        recur(str+")",n,open,closed+1,ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        recur("",n,0,0,ans);
        return ans;

        
    }
};