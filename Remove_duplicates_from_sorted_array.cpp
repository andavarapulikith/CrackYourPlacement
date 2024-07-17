class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int indi=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[indi]){
                nums[indi+1]=nums[i];
                indi++;
                cnt++;
            }
        }
        return cnt;
        
    }
};