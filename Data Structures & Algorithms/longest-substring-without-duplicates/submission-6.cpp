class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cs;
        int res = 0;
        int i = 0;
        for(int k = 0; k < s.size(); k++){
            while(cs.contains(s[k])){
                cs.erase(s[i]);
                i++;
            }
            cs.insert(s[k]);
            res = max(res, k - i + 1);
        }
        return res;
    }
};
