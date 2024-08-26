//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> neighbours(int n){
        map<int,vector<int>>mpp;
        mpp[0]={8,0};
        mpp[1]={2,4,1};
        mpp[2]={1,3,5,2};
        mpp[3]={2,6,3};
        mpp[4]={1,5,7,4};
        mpp[5]={4,6,2,8,5};
        mpp[6]={3,5,9,6};
        mpp[7]={4,8,7};
        mpp[8]={5,7,9,0,8};
        mpp[9]={8,6,9};
        return mpp[n];
    }
    long long getCount(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 10;
        vector<vector<long long>>dp(10,vector<long long>(n+1,0));
        for(int i=0;i<10;i++)
            dp[i][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<10;j++){
                for(auto it: neighbours(j)){
                    dp[j][i] = dp[j][i] + dp[it][i-1];
                }
            }
        }
        long long ans = 0; 
        for(int i=0;i<10;i++){
            ans = ans + dp[i][n];  
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends