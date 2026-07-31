class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> valCounts;
        for(const int& n : nums){
            valCounts[n]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [val, count] : valCounts){
            buckets[count].push_back(val);
        }
        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(const int& b : buckets[i]){
                res.push_back(b);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
