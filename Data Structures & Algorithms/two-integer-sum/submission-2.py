class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for index, num in enumerate(nums):
            complement = target - num
            if complement in map:
                return [map[complement], index]
            map[num] = index
        return []