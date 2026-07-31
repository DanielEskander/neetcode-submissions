class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqNums = unordered_set(nums.begin(), nums.end());
        int res = 0;
        for(const int& n : nums){
            if(uniqNums.contains(n - 1)) continue;

            int length = 1;
            while(uniqNums.contains(n + length)) length++;
            res = max(res, length);
        }
        return res;
    }
};
