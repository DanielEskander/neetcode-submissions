class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA = INT_MIN;
        stack<pair<int, int>> idx_v_h;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!idx_v_h.empty() && heights[i] < idx_v_h.top().second){
                auto [idx, height] = idx_v_h.top();
                idx_v_h.pop();
                start = idx;
                maxA = max(maxA, (i - idx) * height);
            }
            idx_v_h.push({start, heights[i]});
        }

        while(!idx_v_h.empty()){
            auto [idx, height] = idx_v_h.top();
            idx_v_h.pop();
            maxA = max(maxA, (static_cast<int>(heights.size() - idx)) * height);
        }
        return maxA;
    }
};
