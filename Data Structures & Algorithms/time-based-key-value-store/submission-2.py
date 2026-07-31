class TimeMap:
    timestamps = {}
    def __init__(self):
        self.timestamps = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.timestamps:
            self.timestamps[key].append([value, timestamp])
        else:
            self.timestamps[key] = [[value, timestamp]]

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.timestamps:
            return ""
        l = 0
        r = len(self.timestamps[key]) - 1
        res = ""
        while l <= r:
            mid = l + (r - l) // 2
            if self.timestamps[key][mid][1] == timestamp:
                return self.timestamps[key][mid][0]
            elif self.timestamps[key][mid][1] > timestamp:
                r = mid - 1
            else:
                res = self.timestamps[key][mid][0]
                l = mid + 1
        return res
