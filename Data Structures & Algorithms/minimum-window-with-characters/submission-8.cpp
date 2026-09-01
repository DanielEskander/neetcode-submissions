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
        int need = t.size();
        int i = 0;
        for(int k = 0; k < s.size(); k++){
            sm[s[k]]++;

            if(sm[s[k]] == tm[s[k]])
                have++;
            
            while(have == need){
                if(res.empty() || res.size() > k - i + 1){
                    res = s.substr(i, k - i + 1);
                }
                sm[s[i]]--;
                if(sm[s[i]] < tm[s[i]]) have--;
                i++;
            }
        }
        return res;
    }
};
