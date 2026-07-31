class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        int rowL = 0, rowR = rows;
        int targetR = -1;
        while(rowL <= rowR){
            int rowMid = rowL + (rowR - rowL) / 2;
            if(matrix[rowMid][0] <= target && matrix[rowMid][cols] >= target){
                targetR = rowMid;
                break;
            }
            else if(matrix[rowMid][0] > target){
                rowR = rowMid - 1;
            }
            else{
                rowL = rowMid + 1;
            }
        }

        if(targetR < 0) return false;

        int colL = 0, colR = cols;
        while(colL <= colR){
            int colMid = colL + (colR - colL) / 2;
            if(matrix[targetR][colMid] == target){
                return true;
            }
            else if(matrix[targetR][colMid] > target){
                colR = colMid - 1;
            }
            else{
                colL = colMid + 1;
            }
        }
        
        return false;
    }
};
