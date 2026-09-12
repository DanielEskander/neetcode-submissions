class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        // vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for(int i = 2; i < (int)nums.size(); i++){
            int tmp = prev2;
            prev2 = max(prev2, prev1 + nums[i]);
            prev1 = tmp;
        }
        return prev2;
    }
};
