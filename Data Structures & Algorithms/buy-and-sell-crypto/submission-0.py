class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        j = 1
        maxP = 0
        while j < len(prices):
            if prices[i] < prices[j]:
                maxP = max(maxP, prices[j] - prices[i])
            else:
                i += 1
            j += 1
        return maxP