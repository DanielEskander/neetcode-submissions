class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        counts = {}
        for n in nums:
            if n in counts:
                return True
            
            counts[n] = 1
        return False