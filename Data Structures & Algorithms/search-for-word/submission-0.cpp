class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& target, int idx, int r, int c){
        if(r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            target[idx] != board[r][c] || board[r][c] == '#')
            return false;
        
        char tmp = board[r][c];
        board[r][c] = '#';
        if(idx == target.size() - 1)
            return true;
        idx++;
        bool ans = backtrack(board, target, idx, r-1, c) ||
                    backtrack(board, target, idx, r+1, c) ||
                    backtrack(board, target, idx, r, c-1) ||
                    backtrack(board, target, idx, r, c+1);
        board[r][c] = tmp;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(backtrack(board, word, 0, r, c)) return true;
            }
        }
        return false;
    }
};
