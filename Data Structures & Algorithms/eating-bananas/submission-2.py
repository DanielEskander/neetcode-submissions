class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        upper = max(piles) * len(piles)
        lower = 1
        rate = upper
        while lower <= upper:
            mid = lower + (upper - lower) // 2
            totalTime = 0
            for p in piles:
                totalTime += int(math.ceil(float(p) / mid))
            if totalTime > h:
                lower = mid + 1
            else:
                rate = min(rate, mid)
                upper = mid - 1
        return rate