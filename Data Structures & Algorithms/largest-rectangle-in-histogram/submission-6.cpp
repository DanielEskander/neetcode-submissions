class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> idxByH;
        int res = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!idxByH.empty() && idxByH.top().second > heights[i]){
                auto [idx, height] = idxByH.top();
                idxByH.pop();
                start = idx;
                res = max(res, (i - idx) * height);
            }
            idxByH.push({start, heights[i]});
        }

        while(!idxByH.empty()){
            auto [idx, height] = idxByH.top();
            idxByH.pop();
            res = max(res, (static_cast<int>(heights.size()) - idx) * height);
        }
        return res;
    }
};
