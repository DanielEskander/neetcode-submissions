class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        set<int> num_set = set(nums.begin(), nums.end());
        for(const int& n : nums){
            if(num_set.contains(n-1)) continue;
            
            int length = 1;
            while(num_set.contains(n+length)) length++;
            longest = max(longest, length);
        }
        return longest;
    }
};
