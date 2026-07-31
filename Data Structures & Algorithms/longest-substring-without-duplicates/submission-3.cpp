class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniq;
        int maxLen = 0;
        int i = 0;
        for(int j = 0; j < s.size(); j++){
            while(uniq.contains(s[j])){
                uniq.erase(s[i++]);
            }
            maxLen = max(maxLen, j - i + 1);
            uniq.insert(s[j]);
        }
        return maxLen;
    }
};
