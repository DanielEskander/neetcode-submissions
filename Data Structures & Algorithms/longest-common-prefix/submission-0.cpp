class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].find(res) == string::npos){
                res = res.substr(0, res.size() - 1);
            }
        }
        return res;
    }
};