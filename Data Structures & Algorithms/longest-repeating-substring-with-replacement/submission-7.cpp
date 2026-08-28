class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int maxF = 0;
        int i = 0;
        int res = 0;
        for(int j = 0; j < s.size(); j++){
            m[s[j]]++;
            maxF = max(maxF, m[s[j]]);
            
            while((j - i + 1) - maxF > k){
                m[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }
        return res;
    }
};
