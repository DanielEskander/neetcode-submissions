class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r1 = 0; r2 = len(matrix)
        rowf = -1
        rmid = r1 + (r2 - r1) // 2
        while r1 <= r2:
            if(matrix[rmid][0] <= target and matrix[rmid][len(matrix)-1] >= target):
                rowf = rmid
                break
            elif(matrix[rmid][len(matrix)-1] < target):
                r1 = rmid + 1
            else:
                r2 = rmid - 1
            rmid = r1 + (r2 - r1) // 2
        
        if rowf < 0:
            return False
        
        c1 = 0; c2 = len(matrix[rowf]) - 1
        cmid = c1 + (c2 - c1) // 2
        while c1 <= c2:
            if matrix[rowf][cmid] == target:
                return True
            elif matrix[rowf][cmid] > target:
                c2 = cmid - 1
            else:
                c1 = cmid + 1
            cmid = c1 + (c2 - c1) // 2
        return False