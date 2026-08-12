class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(true){
            if(visited.contains(n)) break;
            visited.insert(n);

            n = happyNum(n);
            if(n == 1) return true;
        }
        return false;
    }

    int happyNum(int n){
        int sum = 0;
        while(n > 0){
            int bit = n % 10;
            sum += pow(bit, 2);
            n /= 10;
        }
        return sum;
    }
};
