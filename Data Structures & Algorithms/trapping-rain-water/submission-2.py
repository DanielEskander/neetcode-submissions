class Solution:
    def trap(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        leftMax = height[i]
        rightMax = height[j]
        area = 0
        while i < j:
            if leftMax < rightMax:
                i += 1
                leftMax = max(leftMax, height[i])
                area += leftMax - height[i]
            else:
                j -= 1
                rightMax = max(rightMax, height[j])
                area += rightMax - height[j]
        return area