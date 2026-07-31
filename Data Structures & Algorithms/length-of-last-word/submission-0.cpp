class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(i > 0 && s[i-1] == ' ' && isalnum(s[i])) len = 0;
            len++;
        }
        return len;
    }
};