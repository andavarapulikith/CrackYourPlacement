class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
         int left=0;
    int n=arr.size();
    int m=arr[0].size();
  int top=0;
  int right=m-1;
  int bottom=n-1;
  vector<int>ans;
  while(top<=bottom&& left<=right){
    for(int i=left;i<=right;i++){
      ans.push_back(arr[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
      ans.push_back(arr[i][right]);
    }
    right--;
    if(top<=bottom){
      for(int i=right;i>=left;i--){
        ans.push_back(arr[bottom][i]);
      }
      bottom--;
    }
    if(left<=right){
      for(int i=bottom;i>=top;i--){
        ans.push_back(arr[i][left]);
      }
      left++;
    }
  }
        return ans;
    }
};