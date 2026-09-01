class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        if(x == -1) return n % 2 == 0 ? 1 : -1;

        bool neg = false;
        double res = 1;
        if(n < 0){
            neg = true;
            n = abs(n);
        }
        for(int i = 1; i <= n; i++){
            if(neg){
                res /= x;
            }
            else{
                res *= x;
            }
        }
        return res;
    }
};
