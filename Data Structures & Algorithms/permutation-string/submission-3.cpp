class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_counts(26);
        vector<int> s2_counts(26);

        for(const char& c : s1){
            s1_counts[c - 'a']++;
        }

        int i = 0, k = 0;
        while(k < s2.size()){
            s2_counts[s2[k] - 'a']++;

            if((k - i + 1) == s1.size()){
                if(s1_counts == s2_counts) return true;
                else s2_counts[s2[i++] - 'a']--;
            }

            k++;
        }
        return false;
    }
};
