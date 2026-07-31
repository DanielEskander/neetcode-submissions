class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        map<pair<int, int>, unordered_set<int>> squares;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == '.') continue;

                pair<int, int> square = { r / 3, c / 3};

                int val = board[r][c];
                if(rows[r].contains(val) ||
                    cols[c].contains(val) || 
                    squares[square].contains(val)){
                        return false;
                }

                rows[r].insert(val);
                cols[c].insert(val);
                squares[square].insert(val);
            }
        }
        return true;
    }
};
