class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sCounts;
        unordered_map<char, int> tCounts;

        for(const char& c : t){
            tCounts[c]++;
        }

        int have = 0;
        int need = tCounts.size();
        int i = 0;
        int k = 0;
        string res = "";
        while(k < s.size()){
            sCounts[s[k]]++;

            if(tCounts.contains(s[k]) && sCounts[s[k]] == tCounts[s[k]]) have++;
            while(have == need){
                if(res == "" || res.size() > k - i + 1){
                    res = s.substr(i, k - i + 1);
                }
                sCounts[s[i]]--;
                if(tCounts.contains(s[i]) && sCounts[s[i]] != tCounts[s[i]]) have--;
                i++;
            }
            k++;
        }
        return res;
    }
};
