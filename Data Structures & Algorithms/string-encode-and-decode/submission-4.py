class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        encStr = ""
        for s in strs:
            encStr += str(len(s))
            encStr += "#"
            encStr += s
        return encStr

    def decode(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
        deStr = []
        i = 0
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            j += 1
            deStr.append(s[j:j+length])
            i = j + length
        return deStr