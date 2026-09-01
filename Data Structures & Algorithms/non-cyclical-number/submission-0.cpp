class Solution {
    unordered_set<int> processed;
public:
    bool isHappy(int n) {
        int cur = n;
        while(true){
            if(cur == 1)
                return true;
            if(processed.contains(cur))
                break;
            processed.insert(cur);
            cur = processNum(cur);
        }
        return false;
    }

    int processNum(int n){
        int tmp = n;
        int res = 0;
        while(tmp > 0){
            res += tmp % 10;
            tmp /= 10;
        }
        return res;
    }
};
