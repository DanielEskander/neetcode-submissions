class Solution:
    def minWindow(self, s: str, t: str) -> str:
        res = ""
        countT = {}
        window = {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)
        
        l = 0
        have = 0
        need = len(countT)
        minLen = float("infinity")
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)
            
            if c in countT and countT[c] == window[c]:
                have += 1
            
            while have == need:
                if r - l + 1 < minLen:
                    minLen = r - l + 1
                    res = s[l:r+1]
                
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        return res