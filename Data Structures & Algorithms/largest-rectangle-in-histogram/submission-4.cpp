class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> idxByH;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!idxByH.empty() && idxByH.top().second > heights[i]){
                auto& [index, height] = idxByH.top();
                idxByH.pop();
                start = index;
                res = max(res, (i - index) * height);
            }
            idxByH.push({start, heights[i]});
        }

        while(!idxByH.empty()){
            auto& [index, height] = idxByH.top();
            idxByH.pop();
            res = max(res, (static_cast<int>(heights.size()) - index) * height);
        }
        return res;
    }
};
