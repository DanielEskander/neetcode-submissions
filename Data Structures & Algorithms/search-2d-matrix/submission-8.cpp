class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int row = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[m][0] <= target && matrix[m][matrix[0].size() - 1] >= target){
                row = m;
                break;
            }
            else if(matrix[m][0] > target){
                r--;
            }
            else{
                l++;
            }
        }

        l = 0;
        r = matrix[row].size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[row][m] == target){
                return true;
            }
            else if(matrix[row][m] > target){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};
