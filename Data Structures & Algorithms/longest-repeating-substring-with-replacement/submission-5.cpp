class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> tracker;
        
        int maxFreq = 0;
        int res = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            tracker[s[j]]++;
            maxFreq = max(maxFreq, tracker[s[j]]);

            while(!tracker.empty() && (j - i + 1) - maxFreq > k){
                tracker[s[i++]]--;
            }

            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
