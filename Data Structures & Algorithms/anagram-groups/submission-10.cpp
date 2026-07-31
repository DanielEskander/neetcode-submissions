class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tracker;
        vector<vector<string>> res;
        for(const string& s : strs){
            vector<int> counts(26);
            string key = "";
            for(const char& c : s){
                counts[c - 'a']++;
            }
            for(const int& i : counts){
                key += to_string(i);
                key += "#";
            }
            if(tracker.contains(key)) tracker[key].push_back(s);
            else tracker[key] = {s};
        }

        for(const auto d : tracker){
            res.push_back(d.second);
        }
        return res;
    }
};
