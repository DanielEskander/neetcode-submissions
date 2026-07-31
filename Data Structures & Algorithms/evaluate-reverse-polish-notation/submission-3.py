class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        mathTime = []
        for token in tokens:
            if token in "+-*/":
                op2 = int(mathTime[-1])
                mathTime.pop()
                op1 = int(mathTime[-1])
                mathTime.pop()
                if token == "+":
                    mathTime.append(str(op1 + op2))
                elif token == "-":
                    mathTime.append(str(op1 - op2))
                elif token == "*":
                    mathTime.append(str(op1 * op2))
                else:
                    if op2 == 0:
                        mathTime.append("0")
                    else:
                        mathTime.append(str(int(op1 / op2)))
            else:
                mathTime.append(token)
        return int(mathTime[-1])