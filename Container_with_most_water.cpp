class Solution {
public:
    int maxArea(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int maxi=(high-low)*min(nums[high],nums[low]);
        while(low<high){
            maxi=max(maxi,(high-low)*min(nums[low],nums[high]));
            if(nums[low]<nums[high])
            low++;
            else
            high--;
        }
        return maxi;
        
    }
};