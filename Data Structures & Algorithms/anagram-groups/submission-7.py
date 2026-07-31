class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = {}
        for s in strs:
            counts = [0] * 26 # counts = [0 for _ in range(26)]
            key = ""
            for c in s:
                counts[ord(c) - 97] += 1
            for count in counts:
                key += str(count)
                key += "#"
            if key not in map:
                map[key] = [s]
            else:
                map[key].append(s)
        
        res = []
        for key,bucket in map.items():
            res.append(bucket)
        return res