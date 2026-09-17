class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& cur, int idx){
        res.push_back(cur);

        for(int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, cur, 0);
        return res;
    }
};
