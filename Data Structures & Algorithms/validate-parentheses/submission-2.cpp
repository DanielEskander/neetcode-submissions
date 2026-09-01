class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for(const char& c : s){
            if(c == '(' || c == '{' || c == '[') chars.push(c);
            else if(!(c == ')' || c == '}' || c == ']')) continue;
            else if(chars.empty()) return false;
            else if(chars.top() == '(' && c == ')' || 
                    chars.top() == '{' && c == '}' ||
                    chars.top() == '[' && c == ']') chars.pop();
        }
        return true;
    }
};
