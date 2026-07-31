class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1Counts = [0] * 26
        s2Counts = [0] * 26
        for c in s1:
            s1Counts[ord(c.lower()) - 97] += 1
        
        i = 0
        for j in range(len(s2)):
            s2Counts[ord(s2[j].lower()) - 97] += 1
            
            while (j - i + 1) > len(s1):
                s2Counts[ord(s2[i].lower()) - 97] -= 1
                i += 1
            
            if((j - i + 1) == len(s1) and s1Counts == s2Counts):
                return True
        return False