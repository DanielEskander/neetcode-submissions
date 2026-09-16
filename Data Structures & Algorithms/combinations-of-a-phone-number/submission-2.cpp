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
    void backtrack(string& digits, string& cur, int idx){
        if(!cur.empty() && cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }

        if(numVals.find(digits[idx]) != numVals.end()){
            for(char& c : numVals[digits[idx]]){
                cur.push_back(c);
                backtrack(digits, cur, idx + 1);
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
