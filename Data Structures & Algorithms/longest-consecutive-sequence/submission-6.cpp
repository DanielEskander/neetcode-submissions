class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniq = unordered_set(nums.begin(), nums.end());
        int maxL = 0;
        for(int n : nums){
            if(uniq.contains(n-1)) continue;

            int length = 1;
            while(uniq.contains(n + length)) length++;

            maxL = max(maxL, length);
        }
        return maxL;
    }
};
