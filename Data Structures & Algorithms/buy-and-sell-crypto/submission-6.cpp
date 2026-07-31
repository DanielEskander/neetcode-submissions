class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int i = 0, j = 0;
        while(j < prices.size()){
            if(prices[i] < prices[j]){
                res = max(res, prices[j] - prices[i]);
            }
            else{
                i = j;
            }
            j++;
        }
        return res;
    }
};
