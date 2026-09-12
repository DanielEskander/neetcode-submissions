class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i < (int)cost.size(); i++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[(int)cost.size()-2], cost[(int)cost.size()-1]);
    }
};
