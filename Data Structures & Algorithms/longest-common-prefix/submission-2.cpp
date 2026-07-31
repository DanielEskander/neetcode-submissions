class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = strs[0];
        for(int i = 0; i < min(strs[0].size(), strs[strs.size() - 1].size()); i++){
            if(strs[0][i] != strs[strs.size()-1][i]){
                return res.substr(0, i);
            }
        }
        return res;
    }
};