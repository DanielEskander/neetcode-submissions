class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> temps;
        vector<int> ans(temperatures.size(), 0);
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!temps.empty() && temperatures[i] >= temps.back().first){
                temps.pop_back();
            }

            if(!temps.empty() && temperatures[i] < temps.back().first){
                ans[i] = temps.back().second - i;
            }
            temps.push_back({temperatures[i], i});
        }
        return ans;
    }
};
