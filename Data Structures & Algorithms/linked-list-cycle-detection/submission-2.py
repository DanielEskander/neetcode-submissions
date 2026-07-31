# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        rab = head
        tur = head
        while rab and rab.next:
            rab = rab.next.next
            tur = tur.next

            if rab == tur:
                return True
        return False