class Solution {
public:
    vector<string> res;
    void backtrack(int& n, string& cur, int open, int close){
        if(cur.size() == 2 * n){
            res.push_back(cur);
            return;
        }

        if(open < n){
            cur.push_back('(');
            backtrack(n, cur, open + 1, close);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            backtrack(n, cur, open, close + 1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        backtrack(n, cur, 0, 0);
        return res;
    }
};
