class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int l=sum-k;
            if(mpp.find(l)!=mpp.end())
            {
            ans+=mpp[l];
            }
            mpp[sum]++;
        }
        return ans;
        
    }
};