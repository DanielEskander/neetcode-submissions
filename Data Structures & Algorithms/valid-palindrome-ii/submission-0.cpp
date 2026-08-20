class Solution {
public:
    bool palindrome(string s, int i, int j, bool used){
        if(i >= j) return true;

        if(s[i] != s[j]){
            if(!used){
                return palindrome(s, i + 1, j, true) || palindrome(s, i, j - 1, true);
            }
            else{
                return false;
            }
        }
        return palindrome(s, i + 1, j - 1, used);
    }
    bool validPalindrome(string s) {
        return palindrome(s, 0, s.size() - 1, false);
    }
};