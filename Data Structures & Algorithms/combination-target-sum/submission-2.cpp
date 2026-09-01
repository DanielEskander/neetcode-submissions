class Solution {
public:
    void makeCombinations(vector<int>& nums, int target, vector<vector<int>>& res, int index, vector<int> cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target < 0 || index >= nums.size())
            return;

        cur.push_back(nums[index]);
        makeCombinations(nums, target - nums[index], res, index, cur);

        cur.pop_back();
        makeCombinations(nums, target, res, index + 1, cur);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        makeCombinations(nums, target, res, 0, {});
        return res;
    }
};
