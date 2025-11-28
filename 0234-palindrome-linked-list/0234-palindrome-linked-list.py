# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self,head: Optional[ListNode]) -> Optional[ListNode]:

        currNode : Optional[ListNode] = head
        prevNode : Optional[ListNode]  = None
        nextNode : Optional[ListNode]

        while currNode != None:
            nextNode = currNode.next
            currNode.next = prevNode

            prevNode = currNode
            currNode = nextNode
        
        return prevNode



    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow : Optional[ListNode] = head
        fast : Optional[ListNode] = head

        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        

        p : Optional[ListNode] = head

        q : Optional[ListNode] =  self.reverseList(slow)


        while p != None and q != None:
            if p.val != q.val:
                return False
            
            p = p.next
            q = q.next

        return True
        