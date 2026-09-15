class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>& cur, int r, int c, int n) {
        // Check column
        for (int i = 0; i < r; i++) {
            if (cur[i][c] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (cur[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (cur[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void backtrack(int& n, vector<string>& cur, int r){
        if(r == n){
            res.push_back(cur);
            return;
        }

        for(int c = 0; c < n; c++){
            if(isSafe(cur, r, c, n)){
                cur[r][c] = 'Q';
                backtrack(n, cur, r + 1);
                cur[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        backtrack(n, cur, 0);
        return res;
    }
};
