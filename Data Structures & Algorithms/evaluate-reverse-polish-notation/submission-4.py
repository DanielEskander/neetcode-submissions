class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        res = []
        for token in tokens:
            if token in "+-*/":
                op2 = res[-1]
                res.pop()
                op1 = res[-1]
                res.pop()
                if token == "+":
                    op1 += op2
                elif token == "-":
                    op1 -= op2
                elif token == "*":
                    op1 *= op2
                elif token == "/":
                    if op2 == 0:
                        op1 = 0
                    else:
                        op1 = int(float(op1) / op2)
                res.append(op1)
            else:
                res.append(int(token))

        return res[-1]