class Solution {
public:
    void recur(int indi, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = indi; i < candidates.size(); ++i) {
            if (i > indi && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            recur(i + 1, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recur(0, candidates, target, temp, ans);
        return ans;
    }
};
