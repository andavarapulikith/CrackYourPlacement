class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
        maxi+=cardPoints[i];
        int curr=maxi;
        for(int i=k-1;i>=0;i--){
             curr-=cardPoints[i];
             curr+=cardPoints[n-k+i];
             maxi=max(maxi,curr);
        }
        return maxi;
             
    }
};