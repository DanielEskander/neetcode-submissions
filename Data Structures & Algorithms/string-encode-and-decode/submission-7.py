class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) < 1:
            return ""
        
        res = ""
        for s in strs:
            res += str(len(s))
            res += "#"
            res += s
        return res

    def decode(self, s: str) -> List[str]:
        if len(s) < 1:
            return []
        i = 0
        res = []
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            j += 1
            res.append(s[j:j+length])
            i = j + length
        return res