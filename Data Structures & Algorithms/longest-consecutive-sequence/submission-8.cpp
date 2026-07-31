class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet = unordered_set(nums.begin(), nums.end());
        int res = 0;

        for(const int& n : numSet){
            if(numSet.contains(n - 1)) continue;

            int length = 1;
            while(numSet.contains(n+length)){
                length++;
            }
            res = max(length, res);
        }
        return res;
    }
};
