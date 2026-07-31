class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> groups;

        for(const string& s : strs){
            string key = "";
            vector<int> counts(26);
            for(const char& c : s){
                counts[c - 'a']++;
            }
            for(const int& c : counts){
                key += to_string(c);
                key += "#";
            }
            groups[key].push_back(s);
        }

        for(auto& [key, group] : groups){
            res.push_back(group);
        }
        return res;
    }
};
