class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> counts;
        for(int n : nums){
            counts[n]++;
        }

        for(pair count : counts){
            buckets[count.second].push_back(count.first);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(int val : buckets[i]){
                res.push_back(val);
                if(res.size() >= k) return res;
            }
        }
        return res;
    }
};
