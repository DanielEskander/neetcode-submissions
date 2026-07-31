class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        buckets = [[] for _ in range(len(nums) + 1)]

        for n in nums:
            counts[n] = counts.get(n, 0) + 1
        
        
        for num,count in counts.items():
            buckets[count].append(num)
        print(buckets)
        
        res = []
        for i in range(len(buckets) - 1, -1, -1):
            for b in buckets[i]:
                res.append(b)
                if len(res) == k:
                    return res
        return res