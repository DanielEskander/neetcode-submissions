class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, nums.size() - 1),
                   robRange(nums, 1, nums.size()));
    }

    int robRange(vector<int>& nums, int start, int end){
        int prev = nums[start];
        int cur = max(nums[start + 1], nums[start]);
        for(int i = start + 2; i < end; i++){
            int temp = cur;
            cur = max(cur, nums[i] + prev);
            prev = temp;
        }
        return cur;
    }
};
