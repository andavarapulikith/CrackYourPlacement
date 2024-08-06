class Solution {
public:
    int predicate(vector<int>&nums,int mid,int k){
        int cnt=1;
        int n=nums.size();
        int curr=0;
        for(int i=0;i<n;i++){
            if(curr+nums[i]<=mid)
            curr+=nums[i];
            else{
                cnt++;
                curr=nums[i];
            }
            if(cnt>k)
            return 0;

        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           maxi=max(maxi,nums[i]);
           sum+=nums[i];
        }
        int low=maxi;
        int high=sum;
        int result;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(predicate(nums,mid,k))
            {
                high=mid-1;
                result=mid;
            }
            else
            low=mid+1;
        }
        return result;
        
    }
};