class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 1;
        int res = upper;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            int time = 0;
            for(auto p : piles){
                time += ceil((p + 0.0) / mid);
            }

            if(time <= h){
                upper = mid - 1;
                res = mid;
            }
            else{
                lower = mid + 1;
            }
        }
        return res;
    }
};
