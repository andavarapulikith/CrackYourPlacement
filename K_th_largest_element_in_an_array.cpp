class Solution {
public:
    int partition(vector<int>& nums, int l, int r,int k) {
        int i = l;
        int j = r;
        // int mid = l + (r - l) / 2;
        int pivot = nums[l];
        // swap(nums[mid], nums[l]);  
        while (i < j) 
        {
            while (i < r && nums[i] <= pivot)
                i++;
            while (j > l && nums[j] > pivot)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[l]);
        if(k==j)
        return nums[k];
        if(k<j)
        return partition(nums,l,j-1,k);
        else
        return partition(nums,j+1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums,0,nums.size()-1,nums.size()-k);
        
    }
};