# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:

        slow : Optional[ListNode] = head
        fast : Optional[ListNode] = head

        
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

            if fast == slow:
                slow : Optional[ListNode] = head

                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                
                return slow

        
        return None
        
        

        