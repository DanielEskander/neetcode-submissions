class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, int target, vector<int> cur, int i){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        
        for(int j = i; j < nums.size(); j++){
            if(target - nums[j] < 0 || (j > i && nums[j] == nums[j-1]))
                return;
            
            cur.push_back(nums[j]);
            dfs(nums, res, target - nums[j], cur, j + 1);

            cur.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        dfs(candidates, res, target, {}, 0);
        return res;
    }
};
