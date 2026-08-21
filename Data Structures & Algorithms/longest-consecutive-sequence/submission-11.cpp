class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s = unordered_set(nums.begin(), nums.end());
        int res = 0;
        for(auto n : s){
            if(s.contains(n-1)) continue;

            int length = 1;
            while(s.contains(n+length)) length++;
            res = max(res, length);
        }
        return res;
    }
};
