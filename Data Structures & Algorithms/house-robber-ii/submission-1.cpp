class Solution {
public:
    int rob(vector<int>& nums) {
        return max(robRange(nums, 0, nums.size() - 1),
                   robRange(nums, 1, nums.size()));
    }

    int robRange(vector<int>& nums, int start, int end){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i < end; i++){
            int tmp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = tmp;
        }
        return prev1;
    }
};
