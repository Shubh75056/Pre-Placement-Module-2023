class Solution {
    int rows,cols;
    vector<vector<bool>> vis;
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i<0||i>=rows||j<0||j>=cols||board[i][j]=='X'||vis[i][j]) return;
        vis[i][j]=true;
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        rows=board.size();
        cols=board[0].size();
        
        vis.resize(rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if((i==0||i==rows-1||j==0||j==cols-1)&&(board[i][j]=='O'))
                    dfs(board,i,j);
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(!vis[i][j]&&board[i][j]=='O')
                {
                    vis[i][j]=true;
                    board[i][j]='X';
                }
            }
        }