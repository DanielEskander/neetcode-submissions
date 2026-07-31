class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 1;
        int rate = upper;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            int totalTime = 0;
            for(int p : piles){
                totalTime += (int)(ceil(((double)p) / mid));
            }

            if(totalTime > h){
                lower = mid + 1;
            }
            else{
                rate = min(rate, mid);
                upper = mid - 1;
            }
        }
        return rate;
    }
};
