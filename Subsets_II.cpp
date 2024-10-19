class Solution {
public:
    void recur(vector<int>& nums, int indi, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = indi; i < nums.size(); i++) {
            if (i > indi && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            recur(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recur(nums, 0, temp, ans);
        return ans;  
    }
};
