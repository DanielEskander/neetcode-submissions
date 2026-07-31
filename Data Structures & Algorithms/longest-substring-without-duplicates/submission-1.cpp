class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniq_c;
        int max_len = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            while(uniq_c.contains(s[j])){
                uniq_c.erase(s[i]);
                i++;
            }
            uniq_c.insert(s[j]);
            max_len = max(max_len, j - i + 1);

            j++;
        }
        return max_len;
    }
};
