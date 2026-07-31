class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tracker = {}
        res = []
        for s in strs:
            count = [0 for _ in range(26)]
            key = ""
            for c in s:
                count[ord(c) - ord('a')] += 1
            for c in count:
                key += str(c)
                key += "#"
            if key in tracker:
                tracker[key].append(s)
            else:
                tracker[key] = [s]

        for k,v in tracker.items():
            res.append(v)
        return res