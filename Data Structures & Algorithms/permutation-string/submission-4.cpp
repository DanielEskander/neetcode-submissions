class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Counts(26);
        vector<int> s2Counts(26);

        for(auto s : s1){
            s1Counts[s - 'a']++;
        }

        int i = 0;
        for(int k = 0; k < s2.size(); k++){
            s2Counts[s2[k] - 'a']++;
            
            if(s1Counts == s2Counts)
                return true;
            
            while(s2Counts[s2[k] - 'a'] > s1Counts[s2[k] - 'a']){
                s2Counts[s2[i] - 'a']--;
                i++;
            }
        }
        return false;
    }
};
