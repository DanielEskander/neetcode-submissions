class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        return unordered_set(nums.begin(), nums.end()).size() != size;
    }
};