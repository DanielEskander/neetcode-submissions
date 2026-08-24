class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, nums.size() - 1),
                   robRange(nums, 1, nums.size()));
    }

    int robRange(vector<int>& nums, int start, int end){
        vector<int> dp(end);

        dp[start] = nums[start];
        dp[start + 1] = max(nums[start + 1], nums[start]);
        for(int i = start + 2; i < end; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
            cout << i << " ";
            cout << dp[i];
            cout << endl;
        }
        return dp[end-1];
    }
};
