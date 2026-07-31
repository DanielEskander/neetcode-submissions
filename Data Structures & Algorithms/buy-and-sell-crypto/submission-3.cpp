class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];
        for(const int& p : prices){
            maxP = max(maxP, p - minBuy);
            minBuy = min(p, minBuy);
        }
        return maxP;
    }
};
