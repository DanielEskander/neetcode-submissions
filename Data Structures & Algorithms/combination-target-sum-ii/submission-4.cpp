class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> cur, int target, int idx){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(target - nums[i] < 0)
                continue;
            if(i > idx && nums[i] == nums[i-1])
                continue;
            
            cur.push_back(nums[i]);
            backtrack(nums, cur, target - nums[i], i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, {}, target, 0);
        return res;
    }
};
