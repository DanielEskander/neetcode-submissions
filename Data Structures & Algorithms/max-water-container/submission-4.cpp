class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = INT_MIN;
        int i = 0, j = heights.size() - 1;
        while(i < j){
            maxA = max(maxA, min(heights[i], heights[j]) * (j - i));
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxA;
    }
};
