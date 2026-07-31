class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        prefixSum = [1 for _ in range(size)]
        suffixSum = [1 for _ in range(size)]
        ans = []

        for i in range(1, size):
            prefixSum[i] = nums[i - 1] * prefixSum[i - 1]
        for i in range(size - 2, -1, -1):
            suffixSum[i] = nums[i + 1] * suffixSum[i + 1]
        for i in range(size):
            ans.append(prefixSum[i] * suffixSum[i])
        return ans