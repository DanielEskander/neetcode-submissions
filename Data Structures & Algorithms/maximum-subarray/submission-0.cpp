class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int bestMax = nums[0];
        for(int i = 0; i < nums.size(); i++){
            curMax = max(nums[i], curMax + nums[i]);
            bestMax = max(curMax, bestMax);
        }
        return bestMax;
    }
};
