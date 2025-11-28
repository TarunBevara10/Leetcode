class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next          # move 1 step
            fast = fast.next.next     # move 2 steps

            if slow == fast:          # pointers meet → cycle exists
                return True

        return False                   # fast reached null → no cycle
