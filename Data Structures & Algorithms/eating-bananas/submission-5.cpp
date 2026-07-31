class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upperB = *max_element(piles.begin(), piles.end());
        int lowerB = 1;
        int res = upperB;
        while(lowerB <= upperB){
            int totalTime = 0;
            int rate = lowerB + (upperB - lowerB) / 2;
            for(auto& v : piles){
                totalTime += ceil((v + 0.0) / rate);
            }

            if(totalTime > h){
                lowerB = rate + 1;
            }
            else{
                upperB = rate - 1;
                res = min(res, rate);
            }
        }
        return res;
    }
};
