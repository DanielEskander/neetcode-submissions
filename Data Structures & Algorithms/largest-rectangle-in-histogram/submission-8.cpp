class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!s.empty() && s.top().first > heights[i]){
                auto [h, idx] = s.top();
                s.pop();
                start = idx;
                res = max(res, (i - idx)*h);
            }
            s.push({heights[i], start});
        }

        while(!s.empty()){
            auto [h, idx] = s.top();
            s.pop();
            res = max(res, (static_cast<int>(heights.size()) - idx)*h);
        }
        return res;
    }
};
