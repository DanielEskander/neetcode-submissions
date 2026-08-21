class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int res = INT_MIN;
        while(i < j){
            res = max(res, (j-i)*min(heights[i], heights[j]));
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};
