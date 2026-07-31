class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[r] < nums[mid]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        int pivot = l;
        l = 0, r = nums.size() - 1;
        if(pivot == 0){}
        else if(target >= nums[0]) r = pivot - 1;
        else l = pivot;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
