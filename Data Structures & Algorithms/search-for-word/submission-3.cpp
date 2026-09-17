class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int idx){
        if(r < 0 || r >= board.size() || 
            c < 0 || c >= board[0].size() ||
            word[idx] != board[r][c])
            return false;
        
        char tmp = board[r][c];
        bool res = false;
        board[r][c] = '#';
        if(idx == word.size() - 1){
            return true;
        }

        idx++;
        res = backtrack(board, word, r - 1, c, idx) || 
                backtrack(board, word, r + 1, c, idx) || 
                backtrack(board, word, r, c - 1, idx) ||
                backtrack(board, word, r, c + 1, idx);

        board[r][c] = tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(backtrack(board, word, r, c, 0))
                    return true;
            }
        }
        return false;
    }
};
