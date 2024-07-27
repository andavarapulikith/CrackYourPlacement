class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
         int n=strs.size();
        map<string,vector<string>>mpp;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
               ans.push_back(it.second);
        }
        return ans;
    }
};