class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int minV = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[l] >= nums[mid]){
                r = mid - 1;
            }
            else if(nums[mid] >= nums[r]){
                l = mid + 1;
            }
            minV = min(minV, nums[mid]);
        }
        return minV;
    }
};
