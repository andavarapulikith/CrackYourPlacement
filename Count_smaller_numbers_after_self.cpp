class Solution {
public:
   void merge(vector<pair<int,int>>&vec,vector<int>&ans,int left ,int mid,int right){
    vector<pair<int,int>>temp(right-left+1);
    int i=left;
    int j=mid+1;
    int indi=0;
    while(i<=mid && j<=right){
        if(vec[i].first<=vec[j].first){
            temp[indi++]=vec[j++];
        }
        else{
            ans[vec[i].second]+=right-j+1;
            temp[indi++]=vec[i++];
        }
    }
    while(i<=mid)
    temp[indi++]=vec[i++];
    while(j<=right)
    temp[indi++]=vec[j++];
    for(int i=left;i<=right;i++)
      vec[i]=temp[i-left];
   }
    void mergesort(vector<pair<int,int>>&vec,vector<int>&ans,int left,int right){
        if(left<right){
            int mid=left+(right-left)/2;
            mergesort(vec,ans,left,mid);
            mergesort(vec,ans,mid+1,right);
            merge(vec,ans,left,mid,right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        vector<int>ans(n,0);
        mergesort(vec,ans,0,n-1);
        return ans;
        
    }
};