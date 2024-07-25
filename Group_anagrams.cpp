class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mpp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            map<char,int>freq;
            for(int j=0;j<strs[i].length();j++){
                  freq[strs[i][j]]++;
            }
            mpp[freq].push_back(strs[i]);
        } 
        vector<vector<string>>res;       
        for(auto it=mpp.begin();it!=mpp.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};