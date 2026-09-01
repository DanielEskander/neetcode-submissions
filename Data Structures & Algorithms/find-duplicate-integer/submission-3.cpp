class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = nums[0];
        while(i < nums.size()){
            if(nums[i] < 0)
                return i;
            nums[i] *= -1;
            i = abs(nums[i]);
        }
        return -1;
    }
};
