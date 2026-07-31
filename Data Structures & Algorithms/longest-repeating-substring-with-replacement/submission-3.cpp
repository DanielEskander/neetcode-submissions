class Solution {
public:
    int characterReplacement(string s, int k) {
        // (window_size - maxf) > k
        unordered_map<char, int> counts;
        int i = 0;
        int maxf = INT_MIN;
        int maxLen = INT_MIN;
        for(int j = 0; j < s.size(); j++){
            counts[s[j]]++;
            maxf = max(maxf, counts[s[j]]);

            while(j - i + 1 - maxf > k) counts[s[i++]]--;

            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
