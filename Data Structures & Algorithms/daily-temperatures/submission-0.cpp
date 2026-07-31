class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> temp_w_idx;
        for(int i = 0; i < temperatures.size(); i++){
            while(!temp_w_idx.empty() &&
                    temperatures[i] > temp_w_idx.top().first){
                int idx = temp_w_idx.top().second;
                temp_w_idx.pop();
                res[idx] = i - idx;
            }
            temp_w_idx.push({temperatures[i], i});
        }
        return res;
    }
};
