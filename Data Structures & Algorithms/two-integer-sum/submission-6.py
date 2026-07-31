class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 2:
            return [0, 1]
        
        vals = {}
        for index,num in enumerate(nums):
            complement = target - num
            if complement in vals:
                return [vals[complement], index]
            vals[num] = index
        return []