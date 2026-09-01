class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int slow2 = nums[0];
        while(true){
            slow2 = nums[slow2];
            slow = nums[slow];
            if(slow2 == slow) return slow;
            
        }
        return -1; 
    }
};
