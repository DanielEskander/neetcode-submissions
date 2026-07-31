class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set s = unordered_set(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};