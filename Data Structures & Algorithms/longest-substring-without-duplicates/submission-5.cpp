class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqC;
        int i = 0;
        int j = 0;
        int res = 0;
        while(j < s.size()){
            while(uniqC.contains(s[j])){
                uniqC.erase(s[i]);
                i++;
            }
            uniqC.insert(s[j]);
            res = max(res, (int)uniqC.size());
            j++;
        }
        return res;
    }
};
