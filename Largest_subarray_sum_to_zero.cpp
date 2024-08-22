class Solution {
  public:
    
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        int maxi=0;
        int sum=0;
        map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
           sum+=arr[i];
        //   int diff=-sum;
           if(mpp.find(sum)!=mpp.end()){
               maxi=max(maxi,i-mpp[sum]);
           }
           else
           mpp[sum]=i;
           
        }
        return maxi;
    }
};