class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rowf = 0
        rl = 0; rr = len(matrix) - 1
        while rl <= rr:
            mid = rl + (rr - rl) // 2
            if(matrix[mid][0] <= target and
                matrix[mid][len(matrix[mid]) - 1] >= target):
                rowf = mid
                break
            elif matrix[mid][0] > target:
                rr = mid - 1
            else:
                rl = mid + 1
        
        cl = 0; cr = len(matrix[rowf]) - 1
        while cl <= cr:
            mid = cl + (cr - cl) // 2
            if matrix[rowf][mid] == target:
                return True
            elif matrix[rowf][mid] > target:
                cr = mid - 1
            else:
                cl = mid + 1
        return False