class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            int target = nums[i] * -1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};
