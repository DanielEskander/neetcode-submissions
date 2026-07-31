class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int comp = target - numbers[i];
            if(comp == numbers[j]) return {i+1, j+1};
            else if(comp > numbers[j]) i++;
            else j--;
        }
        return {};
    }
};
