class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> temps;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!temps.empty() && temps.top().first <= temperatures[i]){
                temps.pop();
            }

            if(!temps.empty() && temps.top().first > temperatures[i]){
                res[i] = temps.top().second - i;
            }
            temps.push({temperatures[i], i});
        }
        return res;
    }
};
