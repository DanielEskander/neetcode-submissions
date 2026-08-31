class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        stack<char> lefts;
        for(auto c : s){
            if(m.contains(c)){
                lefts.push(c);
            }
            else if(!lefts.empty() && m[lefts.top()] == c){
                lefts.pop();
            }
            else{
                return false;
            }
        }
        return lefts.empty();
    }
};
