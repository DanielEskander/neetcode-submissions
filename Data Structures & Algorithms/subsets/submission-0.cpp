class Solution {
public:
    vector<int> subset;
    void dfs(int i, vector<int>& nums, vector<vector<int>>& res){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i + 1, nums, res);

        subset.pop_back();
        dfs(i + 1, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};
