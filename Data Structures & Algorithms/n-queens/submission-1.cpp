class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>& cur, int r, int c, int n){
        for(int i = r; i >= 0; i--){
            if(cur[i][c] == 'Q')
                return false;
        }

        for(int dr = r - 1, dc = c - 1; dr >= 0 && dc >= 0; dr -= 1, dc -= 1){
            if(cur[dr][dc] == 'Q')
                return false;
        }

        for(int dr = r - 1, dc = c + 1; dr >= 0 && dc < n; dr -= 1, dc += 1){
            if(cur[dr][dc] == 'Q')
                return false;
        }
        return true;
    }
    void backtrack(int n, vector<string>& cur, int r){
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
