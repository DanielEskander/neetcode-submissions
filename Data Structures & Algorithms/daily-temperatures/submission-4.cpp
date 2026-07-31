class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> tracker;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!tracker.empty() && tracker.top().first <= temperatures[i]){
                tracker.pop();
            }

            if(!tracker.empty() && temperatures[i] < tracker.top().first){
                res[i] = tracker.top().second - i;
            }
            tracker.push({temperatures[i], i});
        }
        return res;
    }
};
