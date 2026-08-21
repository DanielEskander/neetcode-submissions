class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;
        int leftMax = height[i], rightMax = height[j];
        while(i < j){
            if(leftMax < rightMax){
                i++;
                leftMax = max(leftMax, height[i]);
                ans += leftMax - height[i];
            }
            else{
                j--;
                rightMax = max(rightMax, height[j]);
                ans += rightMax - height[j];
            }
        }
        return ans;
    }
};
