//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int indegree[N]={0};
	    vector<int>adj[N];
	    for(auto it:prerequisites){
	        indegree[it.second]++;
	        adj[it.first].push_back(it.second);
	    }
	   // for(int i=0;i<N;i++)
	   // cout<<indegree[i]<<" ";
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty()){
	        int k=q.front();
	        q.pop();
	        for(auto it:adj[k]){
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    for(int i=0;i<N;i++){
	        if(indegree[i]!=0)
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends