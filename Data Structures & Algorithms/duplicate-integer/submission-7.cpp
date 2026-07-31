class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> no_dup = set(nums.begin(), nums.end());
        return no_dup.size() != nums.size();
    }
};