class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int i = 0;
        int j = heights.size() - 1;
        while(i < j){
            int minHeight = min(heights[i], heights[j]);
            int currArea = minHeight * abs(j - i);
            area = max(area, currArea);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return area;
    }
};
