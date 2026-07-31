class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        counts = {}
        for i,n in enumerate(nums):
            comp = target - n
            if comp in counts:
                return [counts[comp], i]
            counts[n] = i
        return []