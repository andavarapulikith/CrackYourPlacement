class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=abs(nums[i])-1;
            if(nums[k]<0)
            ans.push_back(k+1);
            nums[k]*=-1;
        }
        return ans;
        
    }
};