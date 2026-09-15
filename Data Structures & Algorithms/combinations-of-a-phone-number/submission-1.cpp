class Solution {
public:
    vector<string> res;
    unordered_map<char, string> numVals = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(string& digits, int idx, string& cur){
        if(idx == digits.size()){
            res.push_back(cur);
            return;
        }

        for(auto& c : numVals[digits[idx]]){
            cur.push_back(c);
            backtrack(digits, idx + 1, cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string cur;
        if(!digits.empty())
            backtrack(digits, 0, cur);
        return res;
    }
};
