class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> s;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }

            if(!s.empty() && s.top().first > temperatures[i]){
                res[i] = s.top().second - i;
            }

            s.push({temperatures[i], i});
        }
        return res;
    }
};
