# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow : Optional[ListNode] = head
        fast : Optional[ListNode] = head


        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

            if fast != None and slow == fast:
                return True
        
        return False