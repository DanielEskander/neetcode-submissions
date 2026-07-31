class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        buckets = [[] for _ in range(len(nums) + 1)]
        res = []

        for n in nums:
            if n in counts:
                counts[n] += 1
            else:
                counts[n] = 1
        
        for num,count in counts.items():
            buckets[count].append(num)
        
        for i in range(len(buckets) - 1, -1, -1):
            for val in buckets[i]:
                res.append(val)
                if len(res) == k:
                    return res
        
        return res