class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, nums.size() - 1),
                   robRange(nums, 1, nums.size()));
    }

    int robRange(vector<int>& nums, int start, int end){
        int dp2 = nums[start];
        int dp1 = max(nums[start], nums[start+1]);
        for(int i = start + 2; i < end; i++){
            int tmp = dp1;
            dp1 = max(dp1, nums[i] + dp2);
            dp2 = tmp;
        }
        return dp1;
    }
};
