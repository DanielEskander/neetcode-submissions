class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i = 0
        j = len(heights) - 1
        maxA = 0
        while i < j:
            minH = min(heights[i], heights[j])
            currA = minH * (j-i)
            maxA = max(maxA, currA)
            if heights[i] < heights[j]:
                i += 1
            else:
                j -= 1
        return maxA