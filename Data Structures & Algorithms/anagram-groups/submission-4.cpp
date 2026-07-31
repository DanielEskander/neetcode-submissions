class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anas = {};
        for(const string& s : strs){
            int counts[26] = {};
            string key = "";
            for(const char& c : s){
                counts[c - 97]++;
            }
            for(const int& i : counts){
                key.append(to_string(i));
                key.append("#");
            }
            if(anas.contains(key)) anas[key].push_back(s);
            else anas[key] = {s};
        }

        vector<vector<string>> res;
        for(const auto [key, val] : anas){
            res.push_back(val);
        }
        return res;
    }
};
