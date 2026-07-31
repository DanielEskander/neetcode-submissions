class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tracker = {}
        for i,val in enumerate(nums):
            comp = target - val
            if comp in tracker:
                return [tracker[comp], i]
            tracker[val] = i
        return []