class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * ((n + 0.0) / 2);
        for(auto& nu : nums){
            sum -= nu;
        }
        return sum;
    }
};
