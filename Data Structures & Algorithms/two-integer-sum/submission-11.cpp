class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(counts.contains(comp)) return {counts[comp], i};
            counts[nums[i]] = i;
        }
        return {};
    }
};
