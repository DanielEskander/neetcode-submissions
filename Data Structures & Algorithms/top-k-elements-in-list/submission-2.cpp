class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts = {};
        vector<vector<int>> buckets(nums.size() + 1);
        for(const int& n : nums){
            counts[n]++;
        }
        
        for(const auto [num, count] : counts){
            buckets[count].push_back(num);
        }
        
        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(const int& num : buckets[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
