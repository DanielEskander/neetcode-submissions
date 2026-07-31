class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        unordered_set<int> num_set(nums.begin(), nums.end());
        int maxDis = 0;
        for(const int& num : num_set){
            if(num_set.find(num - 1) == num_set.end()){
                int length = 1;
                while(num_set.find(num + length) != num_set.end()){
                    length++;
                }
                maxDis = max(maxDis, length);
            }
        }
        return maxDis;
    }
};
