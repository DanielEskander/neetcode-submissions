class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prof = 0
        i = 0
        j = 1
        while j < len(prices):
            if prices[i] < prices[j]:
                prof = max(prof, prices[j] - prices[i])
            else:
                i = j
            j += 1
        return prof