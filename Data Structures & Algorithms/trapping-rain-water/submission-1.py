class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        i = 0
        j = len(height) - 1
        leftMax = height[i]
        rightMax = height[j]
        while i < j:
            if leftMax < rightMax:
                i += 1
                leftMax = max(leftMax, height[i])
                res += leftMax - height[i]
            else:
                j -= 1
                rightMax = max(rightMax, height[j])
                res += rightMax - height[j]
        return res