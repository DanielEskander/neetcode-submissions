class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int i = 0;
        int maxL = 0;
        for(int j = 0; j < s.size(); j++){
            while(unique.contains(s[j])){
                unique.erase(s[i]);
                i++;
            }
            unique.insert(s[j]);
            maxL = max(maxL, j - i + 1);
        }
        return maxL;
    }
};
