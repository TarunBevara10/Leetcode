class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        # 1️⃣ Step 1 — Insert copied nodes after each original node
        curr = head
        while curr:
            new_node = Node(curr.val, curr.next, None)
            curr.next = new_node
            curr = new_node.next

        # 2️⃣ Step 2 — Assign random pointers to the copied nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # 3️⃣ Step 3 — Separate the two lists
        curr = head
        copy_head = head.next
        copy_curr = copy_head

        while curr:
            curr.next = curr.next.next
            copy_curr.next = copy_curr.next.next if copy_curr.next else None
            curr = curr.next
            copy_curr = copy_curr.next

        return copy_head
