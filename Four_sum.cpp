class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>unique;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int low=j+1;
                int high=n-1;
                while(low<high){
                    long long k=(long long)nums[i]+(long long)nums[j]+(long long)nums[low]+(long long)nums[high];
                    if(k==target)
                    {
                    unique.insert({nums[i],nums[j],nums[low],nums[high]});
                    low++;
                    high--;
                    }
                    else if(k>target)
                    high--;
                    else
                    low++;

                }
            }
        }
       return vector<vector<int>>(unique.begin(),unique.end());
    }
};