class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        counts = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in counts:
                return [counts[comp], i]
            counts[nums[i]] = i
        return []