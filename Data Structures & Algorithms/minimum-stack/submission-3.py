class MinStack:
    s = []
    minS = []
    def __init__(self):
        self.s = []
        self.minS = []        

    def push(self, val: int) -> None:
        self.s.append(val)
        if len(self.minS) == 0 or val < self.minS[-1]:
            self.minS.append(val)
        else:
            self.minS.append(self.minS[-1])

    def pop(self) -> None:
        self.s.pop()
        self.minS.pop()

    def top(self) -> int:
        return self.s[-1]

    def getMin(self) -> int:
        return self.minS[-1]
