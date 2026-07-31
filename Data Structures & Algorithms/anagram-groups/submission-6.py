class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupings = {}
        res = []
        for s in strs:
            key = ""
            counts = [0 for _ in range(26)]
            for c in s:
                counts[ord(c) - 97] += 1
            for count in counts:
                key += str(count) + "#"
            if key in groupings:
                groupings[key].append(s)
            else:
                groupings[key] = [s]
        
        for key,group in groupings.items():
            res.append(group)
        return res