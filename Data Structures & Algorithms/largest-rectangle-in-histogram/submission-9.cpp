class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!s.empty() && s.top().first > heights[i]){
                auto [height, idx] = s.top();
                s.pop();
                start = idx;
                res = max(res, (i - idx) * height);
            }
            s.push({heights[i], start});
        }

        while(!s.empty()){
            auto [height, idx] = s.top();
            s.pop();
            res = max(res, (static_cast<int>(heights.size()) - idx) * height);
        }
        return res;
    }
};
