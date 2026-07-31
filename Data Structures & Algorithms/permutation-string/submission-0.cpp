class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_counts(26);
        for(const char& c : s1){
            s1_counts[c - 97]++;
        }
        vector<int> s2_counts(26);
        int i = 0;
        for(int j = 0; j < s2.size(); j++){
            s2_counts[s2[j] - 97]++;
            if((j - i + 1) > s1.size()){
                s2_counts[s2[i++] - 97]--;
            }
            if((j - i + 1) == s1.size() && s1_counts == s2_counts){
                return true;
            }
        }
        return false;
    }
};
