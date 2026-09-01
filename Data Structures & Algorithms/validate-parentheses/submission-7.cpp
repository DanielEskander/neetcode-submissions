class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false;
        unordered_map<char, char> combos = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        unordered_set<char> rightOps = {')', ']', '}'};
        stack<char> leftOps;
        for(char c : s){
            if(combos.contains(c)) leftOps.push(c);
            if(rightOps.contains(c)){
                if(!leftOps.empty() && combos[leftOps.top()] == c){
                    leftOps.pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
