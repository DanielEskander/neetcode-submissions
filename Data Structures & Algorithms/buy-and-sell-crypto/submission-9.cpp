class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int res = 0;
        while(j < prices.size()){
            if(prices[i] < prices[j]){
                res = max(res, prices[j] - prices[i]);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return res;
    }
};
