# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        idx = 0
        size = 0
        curr = head
        prev = None
        while curr:
            size += 1
            curr = curr.next
        
        curr = head
        while curr:
            if n == size - idx:
                if prev is None:
                    head = head.next
                    return head
                
                prev.next = curr.next
                curr.next = None
                return head

            idx += 1
            prev = curr
            curr = curr.next
        return head