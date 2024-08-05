class Solution {
public:
    int predicate(int n,vector<int>&arr,int k,int mid){
        int cows=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[prev]>=mid){
                cows++;
                prev=i;
            }
        }
        if(cows>=k)
        return 1;
        return 0;
    }
    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(),arr.end());
        int high=arr[n-1]-arr[0];
        int low=high;
        for(int i=1;i<n;i++)
        low=min(low,arr[i]-arr[i-1]);
        while(low+1<high){
            int mid=low+(high-low)/2;
            if(predicate(n,arr,k,mid))
            low=mid;
            else
            high=mid;
        }
        return low;
    }
};