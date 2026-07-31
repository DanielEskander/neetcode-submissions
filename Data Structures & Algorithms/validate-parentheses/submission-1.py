class Solution:
    def isValid(self, s: str) -> bool:
        chars = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                chars.append(c)
            elif(len(chars) > 0 and (c == ')' and chars[-1] == '(' or
                  c == '}' and chars[-1] == '{' or
                  c == ']' and chars[-1] == '[')):
                  chars.pop()
            elif(c == ')' or c == '}' or c == ']'):
                return False
        return len(chars) == 0