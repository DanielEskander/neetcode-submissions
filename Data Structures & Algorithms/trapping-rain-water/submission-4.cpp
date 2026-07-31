class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;
        int maxL = height[i], maxR = height[j];
        while(i < j){
            if(maxL <= maxR){
                i++;
                maxL = max(maxL, height[i]);
                res += maxL - height[i];
            }
            else{
                j--;
                maxR = max(maxR, height[j]);
                res += maxR - height[j];
            }
        }
        return res;
    }
};
