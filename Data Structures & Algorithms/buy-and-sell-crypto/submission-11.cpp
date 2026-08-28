class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int res = 0;
        while(j < prices.size()){
            if(prices[j] > prices[i]){
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
