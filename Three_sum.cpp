class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;
        
        for (int i = 0; i < n - 2; i++) {
            int low = i + 1;
            int high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    uniqueTriplets.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                } else if (sum > 0) {
                    high--;
                } else {
                    low++;
                }
            }
        }
        
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};