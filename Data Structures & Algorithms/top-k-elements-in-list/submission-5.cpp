class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> value_counts = {};
        vector<int> res;
        for(const int& n : nums){
            value_counts[n]++;
        }

        for(const auto& [num,count] : value_counts){
            buckets[count].push_back(num);
        }

        for(int i = buckets.size() - 1; i >= 0; i--){
            for(const int& value : buckets[i]){
                res.push_back(value);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
