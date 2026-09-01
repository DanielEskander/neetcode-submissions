class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        stack<int> times;

        for(const auto [pos, v] : cars){
            int time = (static_cast<double>(target - pos)) / v;
            while(!times.empty() && time <= times.top()) times.pop();

            times.push(time);
        }
        return times.size();
    }
};
