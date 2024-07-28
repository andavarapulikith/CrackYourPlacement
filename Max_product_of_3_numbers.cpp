class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        int maxi3=INT_MIN;
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi1){
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(nums[i]>maxi2){
                maxi3=maxi2;
                maxi2=nums[i];
            }
            else if(nums[i]>maxi3){
                maxi3=nums[i];
            }
            if(nums[i]<mini1){
                mini2=mini1;
                mini1=nums[i];
            }
            else if(nums[i]<mini2)
            {
                mini2=nums[i];
            }
        }
        return max(maxi1*maxi2*maxi3,mini1*mini2*maxi1);
        
    }
};