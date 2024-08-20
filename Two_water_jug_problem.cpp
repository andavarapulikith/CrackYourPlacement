//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int minSteps(int m, int n, int d) {
        // Handle impossible cases
        if (d > max(m, n)) return -1;
        if (d % __gcd(m, n) != 0) return -1;
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        
        q.push({0, 0});  
        visited.insert({0, 0});
        
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int a = q.front().first;  
                int b = q.front().second;
                q.pop();
                if (a == d || b == d) return steps;
                vector<pair<int, int>> nextStates = {
                    {m, b},    
                    {a, n},    
                    {0, b},    
                    {a, 0},    
                    {min(m, a + b), b - (min(m, a + b) - a)},  
                    {a - (min(n, a + b) - b), min(n, a + b)}   
                };
                
                for (auto& state : nextStates) {
                    if (visited.find(state) == visited.end()) {
                        q.push(state);
                        visited.insert(state);
                    }
                }
            }
            steps++;
        }
        
        return -1;  
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends