class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int leftMax = height[i], rightMax = height[j];
        int area = 0;
        while(i < j){
            if(leftMax < rightMax){
                leftMax = max(leftMax, height[++i]);
                area += leftMax - height[i];
            }
            else{
                rightMax = max(rightMax, height[--j]);
                area += rightMax - height[j];
            }
        }
        return area;
    }
};
