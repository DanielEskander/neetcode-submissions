class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> scounts(26);
        vector<int> tcounts(26);
        char e;
        for(char c : s){
            scounts[c - 97]++;
        }

        for(char c : t){
            tcounts[c - 97]++;
        }

        for(int i = 0; i < scounts.size(); i++){
            if(scounts[i] != tcounts[i]) return (char)(i + 97);
        }
        return e;
    }
};