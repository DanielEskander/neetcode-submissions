class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& cur, vector<bool>& visited){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i])
                continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, cur, visited);
        return res;
    }
};
