//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
 
    bool isSafe(bool graph[101][101], int color[], int indi, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (graph[indi][i] && color[i] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(bool graph[101][101], int color[], int indi, int m, int n) {

        if (indi == n) {
            return true;
        }

  
        for (int i = 1; i <= m; i++) {
            if (isSafe(graph, color, indi, i, n)) {
                color[indi] = i;
                if (solve(graph, color, indi + 1, m, n)) {
                    return true;
                }
                color[indi] = 0;
            }
        }

        return false;
    }


    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};  
        if (solve(graph, color, 0, m, n)) {
            return true;
        }

        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends