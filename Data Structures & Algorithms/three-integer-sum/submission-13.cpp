class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // nums[j] + nums[k] = -nums[i]
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;

            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            int target = nums[i]*-1;
            while(j < k){
                if(nums[j] + nums[k] == target){
                    ans.push_back({nums[j], nums[k], nums[i]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                else if(nums[j] + nums[k] < target) j++;
                else k--;
            }
        }
        return ans;
    }
};
