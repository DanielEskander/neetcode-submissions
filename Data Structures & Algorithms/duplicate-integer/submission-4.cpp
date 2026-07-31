class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(const int& n : nums){
            counts[n]++;
        }

        for(const auto [key, value] : counts){
            if(value >= 2) return true;
        }
        
        return false;
    }
};