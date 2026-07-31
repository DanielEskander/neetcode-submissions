class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minB = INT_MAX;
        int i = 0;
        int j = 1;
        while(j < prices.size()){
            if(prices[i] < prices[j]){
                minB = min(minB, prices[i]);
                profit = max(profit, prices[j] - minB);
            }
            else{
                i = j;
            }
            j++;
        }
        return profit;
    }
};
