class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = 1
        ans = [1] * len(nums)
        for i in range(1, len(nums), 1):
            ans[i] = nums[i-1] * prefix
            prefix *= nums[i-1]
        suffix = 1
        for i in range(len(nums) - 2, -1, -1):
            ans[i] *= nums[i+1] * suffix
            suffix *= nums[i+1]
        return ans