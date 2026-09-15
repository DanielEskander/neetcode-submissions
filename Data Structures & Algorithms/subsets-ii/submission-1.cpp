class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& cur, int start){
        res.push_back(cur);

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1])
                continue;
            
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(nums, cur, 0);
        return res;
    }
};
