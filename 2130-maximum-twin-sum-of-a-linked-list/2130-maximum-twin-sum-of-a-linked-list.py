# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode])-> Optional[ListNode]:
        currNode : Optional[ListNode] = head
        prevNode : Optional[ListNode] = None
        nextNode: Optional[ListNode] 


        while currNode != None:
            nextNode = currNode.next
            currNode.next = prevNode

            prevNode = currNode
            currNode = nextNode
        
        return prevNode




    def pairSum(self, head: Optional[ListNode]) -> int:
        slow : Optional[ListNode] = head
        fast : Optional[ListNode] = head
        maxVal : int = -100000

        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        

        p = head
        q = self.reverseList(slow)

        while p != None and q != None:
            maxVal = max(maxVal, p.val + q.val)

            p = p.next
            q = q.next

        
        return maxVal

        



        