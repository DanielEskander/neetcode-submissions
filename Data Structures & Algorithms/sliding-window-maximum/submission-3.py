class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        tracker = deque([])
        i = 0
        for j in range(len(nums)):
            while len(tracker) > 0 and tracker[0][0] < nums[j]:
                tracker.popleft()
            tracker.append((nums[j], j))
            while len(tracker) > 0 and tracker[-1][1] < i:
                tracker.pop()
            if j + 1 >= k:
                res.append(tracker[0][0])
                i += 1
        return res