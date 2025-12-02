class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        # Step 1: Find length and last node
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1

        # Step 2: Make it circular
        tail.next = head

        # Step 3: Effective rotations
        k = k % length
        steps_to_new_tail = length - k - 1

        # Step 4: Find new tail
        new_tail = head
        for _ in range(steps_to_new_tail):
            new_tail = new_tail.next

        # Step 5: New head is next of new_tail
        new_head = new_tail.next

        # Step 6: Break circle
        new_tail.next = None

        return new_head
