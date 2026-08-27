class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, int target, vector<int> cur, int index){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        
        for(int j = index; j < nums.size(); j++){
            if(target - nums[j] < 0)
                continue;

            cur.push_back(nums[j]);
            dfs(nums, res, target - nums[j], cur, j);

            cur.pop_back();    
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        dfs(nums, res, target, {}, 0);
        return res;
    }
};
