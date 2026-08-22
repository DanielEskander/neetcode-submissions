class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> h_by_idx;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!h_by_idx.empty() && h_by_idx.top().first > heights[i]){
                auto [height, index] = h_by_idx.top();
                h_by_idx.pop();
                start = index;
                res = max(res, (i - index) * height);
            }
            h_by_idx.push({heights[i], start});
        }

        while(!h_by_idx.empty()){
            auto [height, index] = h_by_idx.top();
            h_by_idx.pop();
            res = max(res, (static_cast<int>(heights.size()) - index) * height);
        }
        return res;
    }
};
