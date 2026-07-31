class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rt = 0, rb = matrix.size() - 1;
        int row = 0;
        int rmid = rt + (rb - rt) / 2;
    
        while(rt <= rb){
            if(matrix[rmid][0] <= target &&
                matrix[rmid][matrix[0].size() - 1] >= target){
                row = rmid;
                break;
            }
            else if(matrix[rmid][0] > target){
                rb = rmid - 1;
            }
            else{
                rt = rmid + 1;
            }
            rmid = rt + (rb - rt) / 2;
        }

        int cl = 0, cr = matrix[row].size() - 1;
        int cmid = cl + (cr - cl) / 2;
        while(cl <= cr){
            if(matrix[row][cmid] == target){
                return true;
            }
            else if(matrix[row][cmid] < target){
                cl = cmid + 1;
            }
            else{
                cr = cmid - 1;
            }
            cmid = cl + (cr - cl) / 2;
        }
        return false;
    }
};
