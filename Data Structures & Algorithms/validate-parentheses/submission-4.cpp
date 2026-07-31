class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for(const char& c : s){
            if(c == '(' || c == '{' || c == '[') chars.push(c);
            else if(!(c == ')' || c == '}' || c == ']')) continue;
            else if(!chars.empty() && (chars.top() == '(' && c == ')' || 
                    chars.top() == '{' && c == '}' ||
                    chars.top() == '[' && c == ']')) chars.pop();
            else return false;
        }
        return chars.empty();
    }
};
