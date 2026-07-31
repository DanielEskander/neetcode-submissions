class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowf = 0;
        int rl = 0, rr = matrix.size() - 1;
        while(rl <= rr){
            int mid = rl + (rr - rl) / 2;
            if(matrix[mid][0] <= target &&
                matrix[mid][matrix[mid].size() - 1] >= target){
                    rowf = mid;
                    break;
            }
            else if(matrix[mid][0] > target){
                rr = mid - 1;
            }
            else{
                rl = mid + 1;
            }
        }

        int cl = 0, cr = matrix[rowf].size() - 1;
        while(cl <= cr){
            int mid = cl + (cr - cl) / 2;
            if(matrix[rowf][mid] == target){
                return true;
            }
            else if (matrix[rowf][mid] < target){
                cl = mid + 1;
            }
            else{
                cr = mid - 1;
            }
        }
        return false;
    }
};
