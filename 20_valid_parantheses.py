class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        
        for ch in s:
            if ch in mapping:
                # Pop top element if stack not empty, else use dummy '#'
                top = stack.pop() if stack else '#'
                if mapping[ch] != top:
                    return False
            else:
                stack.append(ch)
        
        # If stack is empty, all parentheses matched correctly
        return not stack
