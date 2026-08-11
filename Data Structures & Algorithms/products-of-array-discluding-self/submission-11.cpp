class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int pre = 1;
        for(int i = 1; i < nums.size(); i++){
            ans[i] = nums[i-1] * pre;
            pre *= nums[i-1];
        }

        int suf = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            ans[i] *= nums[i+1] * suf;
            suf *= nums[i+1];
        }
        return ans;
    }
};
