class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        num = 0
        result = 0
        sign = 1   # +1 or -1

        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)

            elif c == '+':
                result += sign * num
                num = 0
                sign = 1

            elif c == '-':
                result += sign * num
                num = 0
                sign = -1

            elif c == '(':
                # Push current result and sign
                stack.append(result)
                stack.append(sign)

                # Reset for new sub-expression
                result = 0
                sign = 1

            elif c == ')':
                result += sign * num
                num = 0

                # Pop and apply previous sign
                prev_sign = stack.pop()
                prev_result = stack.pop()

                result = prev_result + prev_sign * result

        return result + sign * num
