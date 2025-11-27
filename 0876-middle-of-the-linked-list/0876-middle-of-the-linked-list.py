# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow : Optional[ListNode] = head
        fast : Optional[ListNode] = head

        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        

        return slow
        