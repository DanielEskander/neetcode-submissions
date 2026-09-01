class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> tcount, window;
        for(char c : t){
            tcount[c]++;
        }
        int have = 0, need = t.size();
        int l = 0;
        int minLen = INT_MAX;
        for(int r = 0; r < s.size(); r++){
            char curr = s[r];
            window[curr]++;

            if(tcount.contains(curr) && tcount[curr] == window[curr]){
                have++;
            }

            while(have == need){
                if((r - l + 1) < minLen){
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }

                window[s[l]]--;
                if(tcount.contains(s[l]) && window[s[l]] < tcount[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return res;
    }
};
