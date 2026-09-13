class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> cur, int target, int idx){
        if(idx >= nums.size() || target < 0)
            return;
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target - nums[idx] >= 0){
            cur.push_back(nums[idx]);
            backtrack(nums, cur, target - nums[idx], idx);
            cur.pop_back();
        }
        backtrack(nums, cur, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, {}, target, 0);
        return res;
    }
};
