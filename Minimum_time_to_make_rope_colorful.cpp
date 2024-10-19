class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int start=0;
        int end=0;
        int ans=0;
        while(start<n && end<n){
            int maxi=0;
            int sum=0;
            while(end<n && colors[start]==colors[end]){
                maxi=max(maxi,neededTime[end]);
                sum+=neededTime[end];
                end++;
            }
            ans+=sum-maxi;
            start=end;


        }
        return ans;
        
    }
};