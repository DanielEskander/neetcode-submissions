class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int res = 0;
        while(i < j){
            int width = j - i;
            res = max(res, width*min(heights[i], heights[j]));

            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return res;
    }
};
