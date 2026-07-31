class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> my_map;
        vector<vector<string>> ans;
        for(const string& s : strs){
            array<int, 26> alpha = {};
            for(const char& c : s){
                alpha[c - 97] += 1;
            }
            my_map[alpha].push_back(s);
        }
        
        for(auto& pair : my_map){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
