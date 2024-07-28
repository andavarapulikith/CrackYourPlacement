class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        long long int prodvalue=1;
        int zero_cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            zero_cnt++;
            else
            prodvalue*=nums[i];
        }
        vector<long long int>ans(n,0);
        for(int i=0;i<n;i++){
            if(zero_cnt==0)
            ans[i]=prodvalue/nums[i];
            if(zero_cnt==1&& nums[i]==0)
            ans[i]=prodvalue;
        }
        return ans;
    }
};