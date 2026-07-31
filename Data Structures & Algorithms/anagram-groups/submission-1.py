class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = {}
        ans = []
        for s in strs:
            counts = [0] * 26
            key = ""
            for c in s:
                counts[ord(c) - 97] += 1;
            for i in counts:
                key += str(i) + "#"
            if key not in map:
                map[key] = []
            map[key].append(s)
        
        for key,val in map.items():
            ans.append(val)
        return ans