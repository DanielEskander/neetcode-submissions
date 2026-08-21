class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_by_s;
        for(int i = 0; i < position.size(); i++){
            pos_by_s.push_back({position[i], speed[i]});
        }

        sort(pos_by_s.rbegin(), pos_by_s.rend());

        vector<double> times;
        for(int i = 0; i < pos_by_s.size(); i++){
            double time = (0.0 + target - pos_by_s[i].first) / pos_by_s[i].second;
            times.push_back(time);

            while(times.size() >= 2 && times[times.size() - 2] >= times.back()){
                times.pop_back();
            }
        }
        return times.size();
    }
};
