class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int n : nums){
            if(counts.contains(n)) return true;
            counts[n]++;
        }

        return false;
    }
};