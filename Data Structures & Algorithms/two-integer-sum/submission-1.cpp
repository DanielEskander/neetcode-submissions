class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> my_map = {};
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(my_map.contains(complement)) return {my_map[complement], i};
            my_map[nums[i]] = i;
        }
        return {};
    }
};
