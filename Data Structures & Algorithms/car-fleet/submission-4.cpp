class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carDets;
        for(int i = 0; i < position.size(); i++){
            carDets.push_back({position[i], speed[i]});
        }

        sort(carDets.rbegin(), carDets.rend());
        vector<int> orders;
        for(auto [pos, v] : carDets){
            int time = ((double)(target - pos)) / v;
            orders.push_back(time);
            while(orders.size() >= 2 &&
                    orders[orders.size()-1] <= orders[orders.size()-2]){
                orders.pop_back();
            }
        }
        return orders.size();
    }
};
