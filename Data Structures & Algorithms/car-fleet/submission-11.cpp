class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cD;
        for(int i = 0; i < position.size(); i++){
            cD.push_back({position[i], speed[i]});
        }

        sort(cD.rbegin(), cD.rend());
        vector<double> times;
        for(int i = 0; i < cD.size(); i++){
            auto [pos, s] = cD[i];
            double time = (target - pos + 0.0) / s;
            times.push_back(time);

            if(times.size() >= 2 && times[times.size() - 1] <= times[times.size() - 2])
                times.pop_back();
        }
        return times.size();
    }
};
