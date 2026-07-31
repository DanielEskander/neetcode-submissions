class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = -1;
        for(int i = arr.size() - 1; i >= 0; i--){
            int tmp = arr[i];
            arr[i] = greatest;
            if(tmp > greatest){
                greatest = tmp;
            }
        }
        return arr;
    }
};