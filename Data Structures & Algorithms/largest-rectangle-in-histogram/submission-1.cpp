class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        stack<int> indexes;
        for(int i = 0; i < heights.size(); i++){
            while(!indexes.empty() && heights[indexes.top()] > heights[i]){
                int minIdx = indexes.top();
                indexes.pop();

                int width = indexes.empty() ? i : i - indexes.top() - 1;
                maxArea = max(maxArea, heights[minIdx] * width);
            }
            indexes.push(i);
        }

        while(!indexes.empty()){
            int minIdx = indexes.top();
            indexes.pop();

            int width = indexes.empty() ? heights.size() : heights.size() - indexes.top() - 1;
            maxArea = max(maxArea, heights[minIdx] * width);
        }
        return maxArea;
    }
};
