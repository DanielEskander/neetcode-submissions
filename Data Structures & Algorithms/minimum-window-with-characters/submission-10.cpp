class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> tm;
        unordered_map<char, int> sm;
        for(auto c : t){
            tm[c]++;
        }

        int have = 0;
        int need = tm.size();
        int i = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;
        for(int k = 0; k < s.size(); k++){
            sm[s[k]]++;

            if(sm[s[k]] == tm[s[k]])
                have++;
            
            while(i <= k && have == need){
                if(bestLen > k - i + 1){
                   bestLen = k - i + 1;
                   bestStart = i;
                }
                sm[s[i]]--;
                if(sm[s[i]] < tm[s[i]]) have--;
                i++;
            }
        }

        if(bestLen == INT_MAX){
            return "";
        }
        return s.substr(bestStart, bestLen);
    }
};
