class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s : strs){
            string key = "";
            vector<int> count(26);
            for(auto c : s){
                count[c - 'a']++;
            }
            for(auto i : count){
                key += to_string(i);
                key += "#";
            }
            m[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto [k, anas] : m){
            res.push_back(anas);
        }
        return res;
    }
};
