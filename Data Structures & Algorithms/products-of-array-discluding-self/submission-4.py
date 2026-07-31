class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        preProd = [1 for _ in range(len(nums))]
        sufProd = [1 for _ in range(len(nums))]
        ans = []
        for i in range(1, len(nums)):
            preProd[i] = nums[i-1] * preProd[i-1]
        for i in range(len(nums) - 2, -1, -1):
            sufProd[i] = nums[i+1] * sufProd[i+1]
        for i in range(len(nums)):
            ans.append(preProd[i] * sufProd[i])

        return ans