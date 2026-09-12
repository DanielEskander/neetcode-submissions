class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        int prev2 = 2;
        int prev1 = 1;
        int res;
        for(int i = 2; i < n; i++){
            res = prev2 + prev1;
            prev1 = prev2;
            prev2 = res;
        }
        return res;
    }
};
