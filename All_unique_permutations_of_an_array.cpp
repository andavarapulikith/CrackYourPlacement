class Solution {
  public:
  void findpermutations(vector<int>&arr,int indi,set<vector<int>>&ans){
      if(indi==arr.size()){
          ans.insert(arr);
          return;
      }
      for(int i=indi;i<arr.size();i++){
          swap(arr[indi],arr[i]);
          findpermutations(arr,indi+1,ans);
          swap(arr[indi],arr[i]);
          
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        set<vector<int>>ans;
        findpermutations(arr,0,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};