class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        values = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in values:
                return [values[comp], i]
            values[nums[i]] = i
        return []