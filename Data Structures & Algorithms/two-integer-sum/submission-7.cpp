class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> values;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(values.contains(comp)) return {values[comp], i};
            values[nums[i]] = i;
        }
        return {};
    }
};
