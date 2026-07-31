class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mappings = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        stack<char> tracker;
        for(const char& c : s){
            if(mappings.contains(c)) tracker.push(c);
            else if(!tracker.empty() && mappings[tracker.top()] == c) tracker.pop();
            else return false;
        }
        return tracker.empty();
    }
};
