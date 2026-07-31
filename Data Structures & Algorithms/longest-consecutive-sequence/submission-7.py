class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniq = set(nums)
        maxL = 0
        for n in uniq:
            if n - 1 in uniq:
                continue
            
            length = 1
            while n + length in uniq:
                length += 1
            maxL = max(maxL, length)
        return maxL