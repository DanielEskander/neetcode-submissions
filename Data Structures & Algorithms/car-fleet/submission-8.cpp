class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        vector<double> times;

        for(const auto [pos, v] : cars){
            double time = (static_cast<double>(target - pos)) / v;
            times.push_back(time);
            while(times.size() >= 2 && times[times.size() - 2] >= times.back()) times.pop_back();
        }
        return times.size();
    }
};
