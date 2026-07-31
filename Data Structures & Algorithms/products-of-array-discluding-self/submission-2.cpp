class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixSum(len, 1);
        vector<int> suffixSum(len, 1);
        vector<int> ans;

        for(int i = 1; i < len; i++){
            prefixSum[i] = nums[i - 1] * prefixSum[i - 1];
        }

        for(int i = len - 2; i >= 0; i--){
            suffixSum[i] = nums[i + 1] * suffixSum[i + 1];
        }

        for(int i = 0; i < len; i++){
            ans.push_back(prefixSum[i] * suffixSum[i]);
        }

        return ans;
    }
};
