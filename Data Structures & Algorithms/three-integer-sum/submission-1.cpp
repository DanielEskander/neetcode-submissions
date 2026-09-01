class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k && j < nums.size()){
                int target = nums[i] * -1;
                if(nums[j] + nums[k] == target){
                    res.push_back({nums[i], nums[j], nums[k]});
                    break;
                }
                else if(nums[j] + nums[k] > target) k--;
                else j++;
            }
        }
        return res;
    }
};
