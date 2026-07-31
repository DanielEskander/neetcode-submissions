class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0 for _ in range(len(temperatures))]
        tmps = []
        for i in range(len(temperatures)):
            while(len(tmps) > 0 and temperatures[i] > tmps[-1][0]):
                idx = tmps[-1][1]
                tmps.pop()
                res[idx] = i - idx
            tmps.append((temperatures[i], i))
        return res