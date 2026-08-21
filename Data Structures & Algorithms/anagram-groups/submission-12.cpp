class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string& s : strs){
            string key = "";
            vector<int> counts(26);
            for(char& c : s){
                counts[c - 'a']++;
            }
            for(int& c : counts){
                key += to_string(c);
                key += "#";
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto [key, anas] : groups){
            res.push_back(anas);
        }
        return res;
    }
};
