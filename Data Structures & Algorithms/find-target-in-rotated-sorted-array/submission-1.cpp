class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                if(nums[nums.size()-1] >= target){
                    l = mid + 1;
                }
                else{
                    mid--;
                    while(mid >= 0){
                        if(nums[mid] == target) return mid;
                        mid--;
                    }
                    return -1;
                }
            }
            else{
                if(nums[0] <= target){
                    r = mid - 1;
                }
                else{
                    mid++;
                    while(mid < nums.size()){
                        if(nums[mid] == target) return mid;
                        mid++;
                    }
                    return -1;
                }
            }
        }
        return -1;
    }
};
