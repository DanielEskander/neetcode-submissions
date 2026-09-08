class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sCounts;
        unordered_map<char, int> tCounts;

        for(char& c : t){
            tCounts[c]++;
        }

        int have = 0;
        int need = tCounts.size();
        int i = 0;
        int k = 0;
        int resBegin = -1;
        int resSize = INT_MAX;
        while(k < s.size()){
            sCounts[s[k]]++;

            if(tCounts.find(s[k]) != tCounts.end() && sCounts[s[k]] == tCounts[s[k]])
                have++;
            
            while(have == need){
                if(resSize == INT_MAX || resSize > k - i + 1){
                    resSize = k - i + 1;
                    resBegin = i;
                }
                sCounts[s[i]]--;

                if(tCounts.find(s[i]) != tCounts.end() && sCounts[s[i]] < tCounts[s[i]])
                    have--;

                i++;
            }
            k++;
        }
        return resBegin < 0 ? "" : s.substr(resBegin, resSize);
    }
};
