class Solution:
    def isHappy(self, n: int) -> bool:
        
        def get_sum(num):
            s = 0
            while num > 0:
                digit = num % 10
                s += digit * digit
                num //= 10
            return s
        
        slow = n
        fast = get_sum(n)
        
        # Floyd's cycle detection
        while fast != 1 and slow != fast:
            slow = get_sum(slow)
            fast = get_sum(get_sum(fast))
        
        return fast == 1
