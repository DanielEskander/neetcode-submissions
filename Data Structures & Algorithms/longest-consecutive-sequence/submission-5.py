class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniNum = set(nums)
        maxLen = 0
        for n in uniNum:
            if n - 1 in uniNum:
                continue
            
            length = 1
            while n + length in uniNum:
                length += 1
            maxLen = max(length, maxLen)
        return maxLen