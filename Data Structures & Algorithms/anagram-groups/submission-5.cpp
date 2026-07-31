class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for(const string& str : strs){
            int counts[26] = {};
            string key = "";
            for(const char& c : str){
                counts[c - 97]++;
            }
            for(const int& i : counts){
                key += to_string(i) + "#";
            }
            buckets[key].push_back(str);
        }

        vector<vector<string>> res;
        for(const auto [key, anas] : buckets){
            res.push_back(anas);
        }
        return res;
    }
};
