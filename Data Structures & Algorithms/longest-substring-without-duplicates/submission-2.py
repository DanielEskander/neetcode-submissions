class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        uniq = set()
        maxLen = 0
        i = 0
        for j in range(len(s)):
            while s[j] in uniq:
                uniq.remove(s[i])
                i += 1
            uniq.add(s[j])
            maxLen = max(maxLen, j - i + 1)
            j += 1
        return maxLen