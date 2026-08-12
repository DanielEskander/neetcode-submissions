class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() < 2) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int tmp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = tmp;
        }
        return prev1;
    }
};
