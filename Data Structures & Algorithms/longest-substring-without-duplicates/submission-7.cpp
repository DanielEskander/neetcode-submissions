class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int i = 0, k = 0;
        int res = 0;
        while(k < s.size()){
            char cur = s[k];
            while(!chars.empty() && chars.find(cur) != chars.end()){
                chars.erase(s[i]);
                i++;
            }

            chars.insert(cur);
            res = max(res, k - i + 1);
            k++;
        }
        return res;
    }
};
