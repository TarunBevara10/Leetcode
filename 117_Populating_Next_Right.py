"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        # 'head' is the start of the current level we are traversing
        head = root
        
        while head:
            # Create a dummy node to act as the head of the NEXT level
            dummy = Node(0)
            # 'tail' tracks the last node added to the NEXT level's linked list
            tail = dummy
            
            # Traverse the current level using the already established 'next' pointers
            current = head
            while current:
                if current.left:
                    tail.next = current.left
                    tail = tail.next
                if current.right:
                    tail.next = current.right
                    tail = tail.next
                
                # Move to the next node in the current level
                current = current.next
            
            # Move 'head' to the start of the next level (found via dummy.next)
            head = dummy.next
            
        return root