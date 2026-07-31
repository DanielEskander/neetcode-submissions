class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        stack<int> indexes;
        for(int i = 0; i < heights.size(); i++){
            while(!indexes.empty() && heights[indexes.top()] > heights[i]){
                int minI = indexes.top();
                indexes.pop();

                int width = indexes.empty() ? i : i - indexes.top() - 1;
                maxA = max(maxA, heights[minI] * width);
            }
            
            indexes.push(i);
        }

        while(!indexes.empty()){
            int minI = indexes.top();
            indexes.pop();

            int width = indexes.empty() ? heights.size() : heights.size() - indexes.top() - 1;
            maxA = max(maxA, heights[minI] * width);
        }

        return maxA;
    }
};
