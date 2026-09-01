class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1){
            if(n > 1) return false;
            if(flowerbed[0] == 0 || n == 0) return true;
        }
        int count = 0;
        for(int i = 0; i < flowerbed.size() - 1; i++){
            if(flowerbed[i] == 0 && flowerbed[i + 1] == 0){
                i++;
                count++;
            }
        }
        return count >= n;
    }
};