class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, vector<pair<int, int>>& cur){
        cur.push_back({r,c});
        visited[r][c] = true;

        bool touchesBoundary =
            (r == 0 || r == board.size() - 1 ||
             c == 0 || c == board[0].size() - 1);

        for(auto& d : directions){
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= board.size() ||
                nc < 0 || nc >= board[0].size()){
                    continue;
            }

            if(visited[nr][nc] || board[nr][nc] != 'O')
                continue;
            
            if (dfs(board, visited, nr, nc, cur))
                touchesBoundary = true;
        }

        return touchesBoundary;
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if (board[r][c] != 'O' || visited[r][c])
                    continue;

                vector<pair<int, int>> cur;
                bool touchesBoundary = dfs(board, visited, r, c, cur);

                if(!touchesBoundary){
                    for(int i = 0; i < cur.size(); i++){
                        board[cur[i].first][cur[i].second] = 'X';
                    }
                }
            }
            
        }
    }
};
