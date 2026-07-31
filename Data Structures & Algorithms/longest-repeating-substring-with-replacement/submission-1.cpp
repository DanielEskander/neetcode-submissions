class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int max_freq = 0, max_len = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            freqs[s[j]]++;
            max_freq = max(max_freq, freqs[s[j]]);

            while((j - i + 1) - max_freq > k){
                freqs[s[i]]--;
                i++;
            }

            max_len = max(max_len, j - i + 1);
            j++;
        }
        return max_len;
    }
};
