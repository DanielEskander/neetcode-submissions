class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNums = unordered_set(nums.begin(), nums.end());
        int maxLen = 0;
        for(const int& n : uniqueNums){
            if(uniqueNums.contains(n-1)) continue;
            
            int length = 1;
            while(uniqueNums.contains(n+length)){
                length++;
            }
            maxLen = max(maxLen, length);
        }
        return maxLen;
    }
};
