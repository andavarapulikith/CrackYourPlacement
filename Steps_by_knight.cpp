class Solution 
{
    public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& TargetPos, int N)
    {
        int startX = knightPos[0] - 1;
        int startY = knightPos[1] - 1;
        int targetX = TargetPos[0] - 1;
        int targetY = TargetPos[1] - 1;
        
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        
        queue<pair<int, int>> q;
        q.push({startX, startY});
        
        vector<vector<int>> visited(N, vector<int>(N, 0));
        visited[startX][startY] = 1;
        
        int cnt = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x == targetX && y == targetY)
                    return cnt;
                
                for (int k = 0; k < 8; k++) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    
                    if (newX >= 0 && newY >= 0 && newX < N && newY < N && !visited[newX][newY]) {
                        visited[newX][newY] = 1;
                        q.push({newX, newY});
                    }
                }
            }
            cnt++;
        }
        return -1; 
    }
};