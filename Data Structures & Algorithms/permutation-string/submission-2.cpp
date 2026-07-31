class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Counts(26);
        vector<int> s2Counts(26);

        for(char c : s1){
            s1Counts[tolower(c) - 97]++;
        }

        int i = 0;
        for(int j = 0; j < s2.size(); j++){
            s2Counts[tolower(s2[j]) - 97]++;

            while((j - i + 1) > s1.size()) s2Counts[tolower(s2[i++]) - 97]--;

            if((j - i + 1) == s1.size() && s1Counts == s2Counts) return true;
        }
        return false;
    }
};
