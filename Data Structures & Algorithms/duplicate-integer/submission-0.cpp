class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> my_set = set(begin(nums), end(nums));
        return my_set.size() != nums.size();
    }
};