class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int complement = target - nums[i];
            if(nums[j] == complement) return {i, j};
            else if(nums[j] > complement) j--;
            else i++;
        }
        return {};
    }
};
