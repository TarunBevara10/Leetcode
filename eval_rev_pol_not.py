class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t not in "+-*/":
                stack.append(int(t))
            else:
                b = stack.pop()
                a = stack.pop()

                if t == '+':
                    stack.append(a + b)
                elif t == '-':
                    stack.append(a - b)
                elif t == '*':
                    stack.append(a * b)
                else:  # '/'
                    # Use int() to truncate toward zero
                    stack.append(int(a / b))

        return stack[-1]
