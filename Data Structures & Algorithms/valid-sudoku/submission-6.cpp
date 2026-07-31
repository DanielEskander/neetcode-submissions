class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        map<pair<int, int>, unordered_set<int>> squares;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                int value = board[r][c];

                if(value == '.') continue;

                pair<int, int> square = { r / 3, c / 3};

                if(rows[r].contains(value) ||
                    cols[c].contains(value) ||
                    squares[square].contains(value)) return false;

                rows[r].insert(value);
                cols[c].insert(value);
                squares[square].insert(value);
            }
        }
        return true;
    }
};
