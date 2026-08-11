class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() < 2) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        return max(robRange(nums, 0, nums.size() - 1),
                   robRange(nums, 1, nums.size()));
    }

    int robRange(vector<int>& nums, int start, int end){
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);
        for(int i = 2 + start; i < end; i++){
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }

        return prev1;
    }
};
