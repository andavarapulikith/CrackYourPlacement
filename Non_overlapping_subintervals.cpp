class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;

        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int endVal = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (endVal > intervals[i][0]) {
                cnt++;
            } else {
                endVal = intervals[i][1];
            }
        }

        return cnt;        
    }
};