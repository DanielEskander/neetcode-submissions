class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto& n : nums){
            counts[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto [val, count] : counts){
            buckets[count].push_back(val);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(auto& v : buckets[i]){
                res.push_back(v);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
