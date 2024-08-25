class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back())
            temp.push_back(nums[i]);
            else{
                int indi=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[indi]=nums[i];
            }

        }
        return temp.size();
        
    }
};