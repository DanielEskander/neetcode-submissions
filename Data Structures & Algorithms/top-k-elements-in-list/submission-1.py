class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for n in nums:
            if n in counts:
                counts[n] += 1
            else:
                counts[n] = 1
        
        buckets = [[] for _ in range(len(nums) + 1)]
        for num,count in counts.items():
            buckets[count].append(num)
        
        res = []
        for nums in reversed(buckets):
            for n in nums:
                res.append(n)
                if len(res) == k:
                    return res