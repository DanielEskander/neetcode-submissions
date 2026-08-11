class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2){
            return nums[0];
        }
        vector<int> dp = nums;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
        }

        return max(dp[dp.size()-1], dp[dp.size()-2]);
    }
};
