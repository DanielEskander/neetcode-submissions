class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set set_nums = unordered_set(nums.begin(), nums.end());
        int res = 0;
        for(auto n : set_nums){
            if(set_nums.contains(n - 1))
                continue;
            
            int len = 1;
            while(set_nums.contains(n + len)) len++;
            res = max(res, len);
        }
        return res;
    }
};
