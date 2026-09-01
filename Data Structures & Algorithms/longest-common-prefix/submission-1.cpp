class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = strs[0];
        while(strs[strs.size()-1].find(res) == string::npos){
            res = res.substr(0, res.size() - 1);
        }
        return res;
    }
};