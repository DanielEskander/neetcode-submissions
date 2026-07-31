class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        size = len(nums)
        buckets = [[] for _ in range(size + 1)]
        counts = {}
        for n in nums:
            if n in counts:
                counts[n] += 1
            else:
                counts[n] = 1

        for val,count in counts.items():
            buckets[count].append(val)
        
        res = []
        for i in range(size, -1, -1):
            for val in buckets[i]:
                res.append(val)
                if len(res) >= k:
                    return res
        return res