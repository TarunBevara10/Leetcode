class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # 1️⃣ Move `prev` to the node right before `left`
        for _ in range(left - 1):
            prev = prev.next

        # Now prev → node before reversal  
        # start → first node of the segment to reverse
        start = prev.next
        then = start.next

        # 2️⃣ Reverse the sublist using head-insertion technique
        for _ in range(right - left):
            start.next = then.next
            then.next = prev.next
            prev.next = then
            then = start.next

        return dummy.next
