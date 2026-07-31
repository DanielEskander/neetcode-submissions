class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vals = {};
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(vals.contains(complement)) return {vals[complement], i};
            vals[nums[i]] = i;
        }
        return {};
    }
};
