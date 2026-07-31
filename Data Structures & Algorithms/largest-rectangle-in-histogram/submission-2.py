class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        indexes = []
        for i in range(len(heights)):
            while len(indexes) > 0 and heights[indexes[-1]] > heights[i]:
                minIdx = indexes[-1]
                indexes.pop()

                width = i if len(indexes) == 0 else i - indexes[-1] - 1
                maxArea = max(maxArea, heights[minIdx] * width)
            indexes.append(i)
        
        while len(indexes) > 0:
            minIdx = indexes[-1]
            indexes.pop()

            width = len(heights) if len(indexes) == 0 else len(heights) - indexes[-1] - 1
            maxArea = max(maxArea, heights[minIdx] * width)
        return maxArea