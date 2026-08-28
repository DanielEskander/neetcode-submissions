class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        unordered_map<int, int> m;
        for(auto n : nums){
            m[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto [n, c] : m){
            buckets[c].push_back(n);
        }

        for(int i = buckets.size() - 1; i >= 0; i--){
            for(auto val : buckets[i]){
                res.push_back(val);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
