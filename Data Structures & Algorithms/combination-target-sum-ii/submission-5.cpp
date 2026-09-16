class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int target, vector<int>& cur, int idx){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1])
                continue;
            if(target - nums[i] < 0)
                continue;
            
            cur.push_back(nums[i]);
            backtrack(nums, target - nums[i], cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, cur, 0);
        return res;
    }
};
