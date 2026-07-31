class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tracker;
        int i = 0;
        int k = 0;
        int res = 0;
        while(k < s.size()){
            while(!tracker.empty() && tracker.contains(s[k])){
                tracker.erase(s[i++]);
            }
            tracker.insert(s[k++]);
            res = max(res, k - i);
        }
        return res;
    }
};
