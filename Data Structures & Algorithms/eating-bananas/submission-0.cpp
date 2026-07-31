class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        int res = r;
        while(l <= r){
            int k = l + (r - l) / 2;

            long long totalTime = 0;
            for(int p : piles){
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if(totalTime <= h){
                res = k;
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }
        return res;
    }
};
