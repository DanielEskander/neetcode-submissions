class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    vector<vector<string>> res;
    void backtrack(string& s, vector<string>& cur, int idx){
        if(idx == s.size()){
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            string pat = s.substr(idx, i - idx + 1);
            if(!pat.empty() && isPalindrome(pat)){
                cur.push_back(pat);
                backtrack(s, cur, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(s, cur, 0);
        return res;
    }
};
