class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int res = 0;
        int i = 0, j = 0, maxF = 0;
        while(j < s.size()){
            freqs[s[j]]++;
            maxF = max(maxF, freqs[s[j]]);

            while((j - i + 1) - maxF > k){
                freqs[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
