class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buckets = [[] for _ in range(len(nums) + 1)]
        valueCounts = {}
        res = []
        for n in nums:
            if n in valueCounts:
                valueCounts[n] += 1
            else:
                valueCounts[n] = 1
        
        for num,count in valueCounts.items():
            buckets[count].append(num)
        
        for i in range(len(buckets) -1, -1, -1):
            for n in buckets[i]:
                res.append(n)
                if len(res) == k:
                    return res
        
        return res
