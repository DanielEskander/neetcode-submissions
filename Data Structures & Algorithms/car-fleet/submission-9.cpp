class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> posByV;
        for(int i = 0; i < position.size(); i++){
            posByV.push_back({position[i], speed[i]});
        }

        sort(posByV.rbegin(), posByV.rend());
        int res = 0;
        vector<double> times;
        for(int i = 0; i < posByV.size(); i++){
            double time = (target - posByV[i].first + 0.0) / posByV[i].second;
            times.push_back(time);

            if(times.size() >= 2 && times[times.size() - 1] <= times[times.size() - 2]){
                times.pop_back();
            }
        }
        return times.size();
    }
};
