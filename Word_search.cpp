class Solution {
public:
    bool check_word(vector<vector<char>>& board, string word, int indi, int i, int j, vector<vector<int>>& visited) {
        if (indi >= word.length())
            return true;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() &&
                board[newX][newY] == word[indi] && visited[newX][newY] == 0) {
                visited[newX][newY] = 1;
                if (check_word(board, word, indi + 1, newX, newY, visited))
                    return true;
                visited[newX][newY] = 0;  
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool answer = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
                    visited[i][j] = 1;
                    if (check_word(board, word, 1, i, j, visited))
                        return true;
                }
            }
        }
        return false;
    }
};