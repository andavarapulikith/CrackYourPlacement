class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        map<int, int> mpp;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = sum % k;
            if (mod < 0) {
                mod += k;
            }
            if (mpp.find(mod) != mpp.end()) {
                ans += mpp[mod];
            }
            mpp[mod]++;
        }

        return ans;
    }
};