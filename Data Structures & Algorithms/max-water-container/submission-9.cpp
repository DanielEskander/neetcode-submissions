class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int res = INT_MIN;
        while(i < j){
            if(heights[i] < heights[j]){
                res = max(res, (j - i)*heights[i]);
                i++;
            }
            else{
                res = max(res, (j - i)*heights[j]);
                j--;
            }
        }
        return res;
    }
};
