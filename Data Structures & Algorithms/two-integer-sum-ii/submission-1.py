class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers) - 1
        while i < j:
            comp = target - numbers[i]
            if comp == numbers[j]:
                return [i+1, j+1]
            elif comp > numbers[j]:
                i += 1
            else:
                j -= 1
        return []