//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int flag=0;
  
        int count_ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                q.push({i,j});
               
                }
                if(grid[i][j]==1)
                count_ones++;
            }
        }
        if(count_ones==0)
        return 0;
        int cnt=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
   
        while(!q.empty()){
            cnt+=1;
           int size=q.size(); 
           for(int i=0;i<size;i++){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               for(int j=0;j<4;j++){
                   int newx=x+dx[j];
                   int newy=y+dy[j];
                   if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1){
                       
                       count_ones--;
                       grid[newx][newy]=2;
                       q.push({newx,newy});
                   }
               }
               
           }
           if(count_ones==0)
           return cnt;
           
        }
        if(count_ones==0)
        return cnt;
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends