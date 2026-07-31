class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        temps = []
        ans = [0] * len(temperatures)
        for i in range(len(temperatures) - 1, -1, -1):
            while len(temps) > 0 and temperatures[i] >= temps[-1][0]:
                temps.pop()
            
            if len(temps) > 0 and temperatures[i] < temps[-1][0]:
                ans[i] = temps[-1][1] - i
            
            temps.append([temperatures[i], i])
        return ans
