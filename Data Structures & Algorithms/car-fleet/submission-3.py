class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        carDets = []
        for i in range(len(position)):
            carDets.append([position[i], speed[i]])
        
        carDets.sort(reverse=True)

        order = []
        for data in carDets:
            time = (float(target - data[0]) / data[1])
            order.append(time)
            while len(order) >= 2 and order[-1] <= order[-2]:
                order.pop()
            
        return len(order)