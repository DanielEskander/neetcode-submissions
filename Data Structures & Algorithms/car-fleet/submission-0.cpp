class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_w_v;
        for(int i = 0; i < position.size(); i++){
            pos_w_v.push_back({position[i], speed[i]});
        }
        sort(pos_w_v.rbegin(), pos_w_v.rend());
        vector<double> times;
        for(const pair<int, int>& data : pos_w_v){
            times.push_back(((double)(target - data.first) / data.second));
            while(times.size() >= 2 && times.back() <= times[times.size() - 2]){
                times.pop_back();
            }
        }
        return times.size();
    }
};
