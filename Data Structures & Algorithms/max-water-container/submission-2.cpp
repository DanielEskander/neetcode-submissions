class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxA = 0;
        while(i < j){
            int minH = min(heights[i], heights[j]);
            int currA = minH * (j - i);
            maxA = max(maxA, currA);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxA;
    }
};
