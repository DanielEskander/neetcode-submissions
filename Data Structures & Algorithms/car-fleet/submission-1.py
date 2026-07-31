class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        posWV = []
        for i in range(len(position)):
            posWV.append((position[i], speed[i]))
        posWV.sort(reverse=True)

        times = []
        for pos,speed in posWV:
            times.append((float)(target - pos) / speed)
            while len(times) >= 2 and times[-1] <= times[-2]:
                times.pop()
        return len(times)
