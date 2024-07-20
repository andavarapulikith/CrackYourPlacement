class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        int ele=nums[0];
        for(int i=1;i<n;i++){
            if(ele==nums[i]){
                ++cnt;
            }
            else
            {
                --cnt;
                if(cnt==0){
                    cnt=1;
                    ele=nums[i];
                }
            }
        }
        return ele;
    }
};