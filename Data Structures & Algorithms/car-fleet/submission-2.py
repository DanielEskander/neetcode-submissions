class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        carDets = []
        for i in range(len(position)):
            carDets.append([position[i], speed[i]])
        
        carDets.sort(reverse=True)

        order = []
        for data in carDets:
            time = (float(target - data[0]) / data[1])
            while len(order) > 0 and time <= order[-1]:
                order.pop()

            order.append(time)
        return len(order)