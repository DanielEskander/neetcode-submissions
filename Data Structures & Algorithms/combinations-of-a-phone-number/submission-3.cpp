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
    void backtrack(string digits, string& cur, int idx){
        if(digits.empty())
            return;
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < digits.size(); i++){
            for(char& c : numVals[digits[i]]){
                cur.push_back(c);
                backtrack(digits, cur, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string cur;
        backtrack(digits, cur, 0);
        return res;
    }
};
