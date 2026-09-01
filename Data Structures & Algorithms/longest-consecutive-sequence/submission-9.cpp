class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqNums = unordered_set(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < uniqNums.size(); i++){
            if(uniqNums.contains(nums[i] - 1)) continue;

            int length = 1;
            while(uniqNums.contains(nums[i] + length)) length++;
            res = max(res, length);
        }
        return res;
    }
};
