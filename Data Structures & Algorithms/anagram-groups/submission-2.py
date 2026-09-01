class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # map = {[26] : [s1, s2, s3]}
        anas = {}
        for s in strs:
            alpha = [0 for _ in range(26)]
            for c in s:
                alpha[ord(c) - ord('a')] += 1
            if "".join(map(str, alpha)) in anas:
                anas["".join(map(str, alpha))].append(s)
            else:
                anas["".join(map(str, alpha))] = [s]
        res = []
        for key,val in anas.items():
            res.append(val)
        return res