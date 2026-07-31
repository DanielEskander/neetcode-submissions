class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> tracker;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!tracker.empty() && heights[i] < tracker.top().second){
                pair<int, int> point = tracker.top(); tracker.pop();
                int index = point.first;
                int height = point.second;
                res = max(res, (i - index) * height);
                start = index;
            }
            tracker.push({start, heights[i]});
        }

        while(!tracker.empty()){
            pair<int, int> point = tracker.top(); tracker.pop();
            int index = point.first;
            int height = point.second;
            res = max(res, ((int)heights.size() - index) * height);
        }
        return res;
    }
};
