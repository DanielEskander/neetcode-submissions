class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tracker;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(tracker.contains(comp)) return {tracker[comp], i};
            tracker[nums[i]] = i;
        }
        return {};   
    }
};
