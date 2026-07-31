class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        r = max(piles)
        l = 1
        res = r
        while l <= r:
            k = l + (r - l) // 2
            totalTime = 0
            for p in piles:
                totalTime += math.ceil(float(p) / k)
            if totalTime <= h:
                r = k - 1
                res = k
            else:
                l = k + 1
        return res
