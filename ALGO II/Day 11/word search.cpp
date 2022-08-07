class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ret = false;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dfs(board, word, i, j, 0, visited, ret);
            }
        }
        return(ret);
        
    }
    
    void dfs(vector<vector<char>>& board, string word, int i, int j, int l,
            vector<vector<bool>> &visited, bool &ret) {
        if(ret || l == word.size()) {
            ret = true;
            return;
        }
        int m = board.size();
        int n = board[0].size();
        
        if(i < 0 || j < 0|| i>= m || j >= n) {
            return;
        }
        
        if(word[l] != board[i][j]|| visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        for(int kk = 0; kk < 4; ++kk) {
            int x = i + dx[kk];
            int y = j + dy[kk];
            
            dfs(board, word, x, y, l + 1, visited, ret);
        }
        
        visited[i][j] = false;
    }
};