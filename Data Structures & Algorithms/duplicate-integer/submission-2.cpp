class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> num_set = set(nums.begin(), nums.end());
        return num_set.size() != nums.size();
    }
};