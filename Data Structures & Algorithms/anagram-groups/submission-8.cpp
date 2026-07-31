class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for(string s : strs){
            vector<int> counts(26);
            string key = "";
            for(char c : s){
                counts[c - 97]++;
            }
            for(int count : counts){
                key += to_string(count);
                key += "#";
            }
            if(!buckets.contains(key)){
                buckets[key] = {s};
            }
            else{
                buckets[key].push_back(s);
            }
        }
        vector<vector<string>> res;
        for(pair data : buckets){
            res.push_back(data.second);
        }
        return res;
    }
};
