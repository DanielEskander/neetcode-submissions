class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # map = {[26] : [s1, s2, s3]}
        anas = {}
        for s in strs:
            counts = [0 for _ in range(26)]
            key = ""
            for c in s:
                counts[ord(c) - 97] += 1
            for i in counts:
                key += str(i) + "#"
            if key in anas:
                anas[key].append(s)
            else:
                anas[key] = [s]
        res = []
        for key,val in anas.items():
            res.append(val)
        return res