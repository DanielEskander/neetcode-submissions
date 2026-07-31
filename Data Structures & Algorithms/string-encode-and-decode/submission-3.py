class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        res = ""
        for s in strs:
            res += str(len(s))
            res += "#"
            res += s
        return res

    def decode(self, s: str) -> List[str]:
        if s == "":
            return []
        
        i = 0
        res = []
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            length = int(s[i:j])
            res.append(s[j+1:j+length+1])
            i = j + length + 1
        return res
