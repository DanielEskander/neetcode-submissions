class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        combos = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        checker = []
        for c in s:
            if c in combos:
                checker.append(c)
            if c in combos.values():
                if combos[checker[-1]] == c:
                    checker.pop()
                else:
                    return False
        return len(checker) == 0


