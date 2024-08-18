class Solution {
public:
    pair<int,int> num_to_coordinates(int num,int n){
        int r=n-(num-1)/n-1;
        int c=(num-1)%n;
        if(r%2==n%2)
        return {r,n-1-c};
        return {r,c};

    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<int>q;
        q.push(1);
        visited[n-1][0]=1;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int num=q.front();
                if(num==n*n)
                return level;
                q.pop();
                for(int j=1;j<=6;j++){
                    int newnum=num+j;
                    if(newnum>n*n)
                    continue;
                    pair<int,int>cord=num_to_coordinates(newnum,n);
                    int x=cord.first;
                    int y=cord.second;
                    if(visited[x][y]==0){
                        visited[x][y]=1;
                        if(board[x][y]!=-1)
                        q.push(board[x][y]);
                        else
                        q.push(newnum);
                    }

                }
            }
            level++;

        }
        return -1;
        
    }
};