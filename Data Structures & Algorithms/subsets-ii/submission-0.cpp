class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int prevStart = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                idx = prevStart;
            }
            else{
                idx = 0;
            }
            prevStart = res.size();
            for(int j = idx; j < prevStart; j++){
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        return res;
    }
};
