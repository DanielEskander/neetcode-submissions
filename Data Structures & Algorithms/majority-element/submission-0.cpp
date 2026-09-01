class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for(int num : nums){
            if(count == 0){
                res = num;
            }
            else{
                res == num ? count++ : count--;
            }
        }
        return res;
    }
};