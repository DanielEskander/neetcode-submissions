class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, vector<int> cur, int idx){
        if(target == 0){
            res.push_back(cur);
            return;
        }

       for(int j = idx; j < candidates.size(); j++){
            if(target - candidates[j] < 0)
                return;

            if(j > idx && candidates[j] == candidates[j-1])
                continue;
            
            cur.push_back(candidates[j]);
            backtrack(candidates, target - candidates[j], cur, j + 1);
            cur.pop_back();
       }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, {}, 0);
        return res;
    }
};
