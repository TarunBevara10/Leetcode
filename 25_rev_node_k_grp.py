class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 1:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        curr = head

        # Count number of nodes
        count = 0
        while curr:
            count += 1
            curr = curr.next

        # Reverse every k nodes
        curr = prev.next
        while count >= k:
            curr = prev.next
            nxt = curr.next

            # Reverse the k-group using head insertion method
            for _ in range(k - 1):
                curr.next = nxt.next
                nxt.next = prev.next
                prev.next = nxt
                nxt = curr.next

            prev = curr
            count -= k

        return dummy.next
