class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> cur, vector<bool>& used, int i){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int j = 0; j < nums.size(); j++){
            if(used[j])
                continue;
            cur.push_back(nums[j]);
            used[j] = true;
            dfs(nums, res, cur, used, j + 1);

            cur.pop_back();
            used[j] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        dfs(nums, res, {}, used, 0);
        return res;
    }
};
