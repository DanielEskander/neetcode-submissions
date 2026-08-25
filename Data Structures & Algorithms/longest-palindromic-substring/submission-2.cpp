class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int l = 0; l < s.size(); l++){
            int i = l;
            int j = l;
            while(i >= 0 && j < s.size() && s[i] == s[j]){
                if(res.size() < j - i + 1){
                    res = s.substr(i, j - i + 1);
                }
                i--;
                j++;
            }

            i = l;
            j = l + 1;
            while(i >= 0 && j < s.size() && s[i] == s[j]){
                if(res.size() < j - i + 1){
                    res = s.substr(i, j - i + 1);
                }
                i--;
                j++;
            }
        }
        return res;
    }
};
