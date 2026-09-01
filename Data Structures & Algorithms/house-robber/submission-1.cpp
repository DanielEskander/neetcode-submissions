class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        dp.resize(nums.size()+1, 0);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = dp[i-2] + dp[i];
        }

        return max(dp[dp.size()-1], dp[dp.size()-2]);
    }
};
