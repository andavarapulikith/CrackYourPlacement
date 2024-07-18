class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        map<int,int>mpp;
        for(int i=0;i<high;i++){
            int value=target-nums[i];
            if(mpp.find(value)!=mpp.end())
            return {mpp[value],i};
            mpp[nums[i]]=i;
        }
        return {-1};
    }
};