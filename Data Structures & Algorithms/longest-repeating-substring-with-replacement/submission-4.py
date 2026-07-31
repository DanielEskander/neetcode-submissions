class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = {}
        i = 0
        maxf = 0
        maxLen = 0
        for j in range(len(s)):
            if s[j] not in counts:
                counts[s[j]] = 1
            else:
                counts[s[j]] += 1
            maxf = max(maxf, counts[s[j]])

            while((j - i + 1) - maxf > k):
                counts[s[i]] -= 1
                i += 1
            
            maxLen = max(maxLen, j - i + 1)
        return maxLen