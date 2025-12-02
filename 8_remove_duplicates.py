class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        curr = head

        while curr:
            # Detect duplicate block
            if curr.next and curr.val == curr.next.val:
                value = curr.val
                # Skip all nodes with this value
                while curr and curr.val == value:
                    curr = curr.next
                # Connect prev to the next distinct node
                prev.next = curr
            else:
                # Move prev normally if no duplicate
                prev = curr
                curr = curr.next

        return dummy.next
