class Solution {
public:
    vector<string> res;
    void backtrack(int n, int open, int close, string& cur){
        if(cur.size() == 2 * n){
            res.push_back(cur);
            return;
        }

        if(open < n){
            cur.push_back('(');
            backtrack(n, open + 1, close, cur);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            backtrack(n, open, close + 1, cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        backtrack(n, 0, 0, cur);
        return res;
    }
};
