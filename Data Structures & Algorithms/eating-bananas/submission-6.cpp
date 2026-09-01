class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 0;
        int res = upper;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            int time = 0;
            for(auto p : piles){
                time += ceil((p + 0.0) / mid);
            }

            if(time <= h){
                upper--;
                res = min(res, mid);
            }
            else{
                lower++;
            }
        }
        return res;
    }
};
